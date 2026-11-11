#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5009;
ll n,d;
int f[N][N];
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j)f[i][j]=0;
			if(a[j]-d<a[i])f[i][j]=1;
			else {
				for(int k=i;k<j;k++){
					f[i][j]=min(f[i][k]+1,f[i][j]);
			}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<f[1][i]<<' ';
	}
	return 0;
} 
