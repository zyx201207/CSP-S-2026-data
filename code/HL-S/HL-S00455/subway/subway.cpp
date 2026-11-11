#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
long long w[maxn],a[maxn][maxn],t[maxn][maxn];
long long k[maxn];
long long dp[maxn][maxn];
long long ans;
long long jz[maxn][maxn];
bool station[maxn][22];
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int start,arrive;
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
		for(int i=1;i<=n;i++){
			cout<<w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				station[a[i][j]][i]=1;
			}
		}
		
}