#include<bits/stdc++.h>
#define int long long
using namespace std;

const int _=2e6+5;

int n,m;
int a[_],l[_],r[_],vis[_],num[_],sum[_];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(a+1,a+n+1,a[i]-m)-a;
		r[i]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
	}
	for(int i=1;i<=n;i++){
		if(l[i]==l[l[i]+1]&&r[r[l[i]]-1]==i){
//			cout<<'!'<<l[i]<<' '<<i<<'\n';
			vis[l[i]]=1;
			vis[i+1]=-1;
		}
	}
	int L=1;
	for(int i=1;i<=n;i++){
		vis[i]+=vis[i-1];
		if(vis[i])continue;
		else{
			if(L==i)num[i]=1;
			else{
				num[L]=num[i-1]=i-L;
				num[i]=1;
			}
			L=i+1;
		}
	}
	for(int i=1;i<=n;i++)cout<<r[i]<<' ';
	cout<<'\n';
//	for(int i=1;i<=n;i++)cout<<r[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+num[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(r[i]-i+1<=2)continue;
		int r1=r[r[i]-2],r2=r[r[i]-1];
		ans+=num[i]*(sum[r2]-sum[r1]);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
0 1
6 3
1 2 4 6 7 8

3

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
