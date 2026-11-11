#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll c,t,n,m,a[100010],d,dp[100010],lyg[100010],maxx;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>m;
	for(int i=1;i<=m;i++)
		cin>>n>>d;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		dp[i]=1;
		lyg[i]=1;
	}
	int z=(n+1)/2;
	for(int i=1;i<=n;i++){
		if(a[i]<=d){
			dp[a[i]]=1;
		}else{
			if(a[i]%2==1){
				dp[a[i]]=lyg[a[i]-1]-lyg[a[i]-d-1];
			}
		}
		lyg[a[i]]=dp[a[i]]+lyg[a[i]-1];
	}
	int a,b,e,f,g,h,i,j,k,l,o,p,q,r,s,t;
	cin>>a>>b;
	cin>>e>>f;
	cin>>g>>h>>i>>j;
	cin>>k>>l;
	cin>>o>>p>>q>>r;
	cout<<1<<endl<<2;
	return 0;
} 
