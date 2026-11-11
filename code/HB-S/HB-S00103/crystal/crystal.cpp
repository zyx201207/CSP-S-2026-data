#include <bits/stdc++.h>
using namespace std;
long long ans=LONG_LONG_MIN,mina=LONG_LONG_MAX,maxa=LONG_LONG_MIN,n,m,a[500009],b[500009],book[200009],mincha=LONG_LONG_MAX,maxcha=LONG_LONG_MIN;
void dfs(long long p){
	if(p>m){
		memset(book,0,sizeof(book));
		long long cnt=LONG_LONG_MIN;
		for(int i=1;i<=n;i++){
			book[b[i]+100000]++;
		}
		for(int i=mina+100000;i<=maxa+100000;i++){
			cnt=max(book[i],cnt);
		}
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		b[i]++;
		dfs(p+1);
		b[i]--;
		dfs(p+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
		if(i>1){
			long long t=a[i]-a[i-1];
			mincha=min(t,mincha);
			maxcha=max(t,maxcha);
		}
	}
	if(mincha==maxcha){
		long long cha,st,ed;
		if(a[1]==a[n]){
			cout << n;
			return 0;
		}
		else if(a[n]>a[1]){
			cha=1;
			st=n-1;
			ed=1;
		}
		else if(a[n]<a[1]){
			cha=-1;
			st=2;
			ed=n;
		}
		ans=1;
		bool flag=false;
		//cout << "cha:"<<cha<<" st:"<<st<<" ed:"<<ed<<'\n';
		for(int i=st;;i-=cha){
			if(cha==1 && i<ed) break;
			if(cha==-1 && i>ed) break;
			while(a[i]<a[i+cha]){
				a[i]++;
				m--;
				//cout << a[i] << ' '<<a[i+cha] <<' '<< m<<'\n';
				if(m<=0){
					flag=true;
					break;
				}
				}
			//cout << '\n';
			if(a[i]==a[i+cha])ans++;
			if(flag) break;
		}
	}
	else{
		dfs(0);
	}
	cout << ans;
	return 0;
}


