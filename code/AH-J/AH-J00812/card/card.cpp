#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,maxn;
int ans[300005];
bool f[3005];
int now[500005];
int ll[500005],rr[500005];
void solve(){
	for(int i=1;i<=n;i++){
		int r=1;
		now[r]=a[i];
		memset(f,0,sizeof f);
		f[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(f[a[j]]==0){
				r++;
				f[a[j]]=1;
				now[r]=a[j];
			}
			else
				while(now[r]!=a[j])
					f[now[r]]=0,now[r]=0,r--;
		}
		for(int j=1;j<=r;j++)
			ans[now[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
}
void solve2(){
	if(maxn==1){
		cout<<n;
		return;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==1){
			ans[1]++;
			if(a[n]==2)  ans[2]++;
		}
		else{
			ans[2]++;
			if(a[n]==1)  ans[1]++;
		}
	cout<<ans[1]<<' '<<ans[2];
}
void solve3(){
	a[n+1]=67676767;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1]) ans[a[i]]=i;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
}
void solve4(){
	int y_=1;
	ll[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			rr[y_++]=i-1;
			ll[y_]=i;
		}
	}
	rr[y_]=n;
	for(int tt=1;tt<=y_;tt++){
		int i=ll[tt];
		int r=1;
		now[r]=a[i];
		memset(f,0,sizeof f);
		f[a[i]]=1;
		int ksks;
		if(ll[tt]==rr[tt]) ksks=tt+1;
		else ksks=tt;
		for(int j=i+1;ksks<=y_;j=ll[++ksks]){
			if(f[a[j]]==0){
				r++;
				f[a[j]]=1;
				now[r]=a[j];
			}
			else
				while(now[r]!=a[j])
					f[now[r]]=0,now[r]=0,r--;
			
		}
		for(int j=1;j<=r;j++)
			ans[now[j]]+=rr[tt]-ll[tt]+1;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
}
bool ttt(){
	for(int i=2;i<=n;i++)
		if(a[i]<a[i-1]) return 0;
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=5000) solve();//1-12
	else if(maxn<=2) solve2();//13,14
	else if(ttt()) solve3();//20
	else solve4();//15-17
	return 0;
}
