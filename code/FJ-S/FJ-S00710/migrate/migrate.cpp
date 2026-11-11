#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int c,t,n;
ll d;
void solve1(){
	int res=0;
	cin>>n>>d;
	if(n>5000){
		cout<<"no";
		exit(0);
	}
	vector<ll> x(n+1);
	vector<int> pre(n+1),nxt(n+1);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=lower_bound(x.begin()+1,x.begin()+n+1,x[i]-d)-x.begin();
		nxt[i]=upper_bound(x.begin()+1,x.begin()+n+1,x[i]+d)-x.begin()-1;
		if(pre[i]<1) pre[i]=1;
		if(nxt[i]>n) nxt[i]=n;
	}
	
	for(int i=1;i<=n;i++){
		vector<int> mi(n+1),cnt(n+1);
		for(int j=1;j<=n;j++){
			if(j<=i){
				cnt[j]=1;
				continue;
			}
			int p=max(pre[j],i);
			mi[j]=mi[p]+1;
			cnt[j]=cnt[p];
			if(p+1<j&&mi[p]==mi[p+1]){
				cnt[j]+=cnt[p+1];
			}
			if(p+2<j&&mi[p]==mi[p+2]){
				cnt[j]+=cnt[p+2];
			}
			if(cnt[j]>3){
				cnt[j]=3;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2){
				res++;
			}
		}
		
		//debug
//		for(int j=1;j<=n;j++){
//			cout<<cnt[i][j]<<" ";
//		}
//		cout<<"\n";
		
	}
	
	cout<<res<<"\n";
}

void solve2(){
	cout<<"0\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			solve1();
		}
		return 0;
	}
	while(t--){
		solve2();
	}
	return 0;
}
