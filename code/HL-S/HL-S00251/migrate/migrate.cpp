#include<bits/stdc++.h>
#define up(i,j,k) for(int i=j;i<=k;i++)
#define da(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define db double
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#define int long long
using namespace std;
const int N=2e4+5;
int c,t;
int n,d;
ll x[N],sum[N];
int f[N]
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(x,0,sizeof(x));
		memset(sum,0,sizeof(sum));
		up(i,1,n) cin>>x[i],sum[i]=sum[i-1]+x[i];
		up(i,1,n){
			up(j,1,n-i+1){
				int r=j+i-1;
				up(k,j,r){
					if(sum[k]-sum[i-1]<=d&&sum[r]-sum[k-1]<=d)
					f[j][r]=max(f[i][k])
				}
			}
		}
	}
	return 0;
}
/*

*/

