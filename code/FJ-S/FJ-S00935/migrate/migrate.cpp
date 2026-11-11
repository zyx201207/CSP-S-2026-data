#include<bits/stdc++.h>
#define int long long
#define N 2000006
#define NN 5005
using namespace std;

//int dis[NN][NN];
//int disnum[NN][NN];
int f[N],g[N],vs[N];
int n,d,x[N],lma[N],rma[N];

void solve(int k){
	cin>>n>>d;for(int i=0;i<=n+1;i++)x[i]=lma[i]=rma[i]=f[i]=g[i]=vs[i]=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1,j=1;i<=n;i++){while(j<n&&x[j+1]-x[i]<=d)j++;rma[i]=j;}
	for(int i=n,j=n;i>=1;i--){while(j>1&&x[i]-x[j-1]<=d)j--;lma[i]=j;}
//	for(int i=1;i<=n;i++)cout<<rma[i]<<' ';cout<<'\n';
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=rma[i];j++){
//			vs[j]++;
//		}
//	}
	for(int i=n;i>=1;i--){
		g[i]=1;if(rma[i]==i){f[i]=0;continue;}
		if(rma[i]==i+1){f[i]+=f[i+1];;continue;}
		if(rma[i]-i>=2){
			for(int j=rma[rma[i]-2]+1;j<=rma[rma[i]-1];j++){
				f[i]+=g[j];
			}
		}//f[i]+=f[rma[rma[i]-1]~rma[rma[i]]]
		for(int j=rma[rma[i]-1]+1;j<=rma[rma[i]];j++){
			f[i]+=f[j];
		}
	}int ans=0;
//	for(int i=1;i<=n;i++)cout<<g[i]<<' ';cout<<'\n';
//	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	for(int i=1;i<=n;i++)ans+=f[i];
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	for(int i=1;i<=T;i++)solve(i);
	return 0;
}
/*

10 333333333333333327 
-1000000000000000000 -666666666666666673 -333333333333333346 
-111111111111111128 111111111111111090 222222222222222199 
333333333333333308 444444444444444417 666666666666666635 999999999999999962

ans:9

*/
