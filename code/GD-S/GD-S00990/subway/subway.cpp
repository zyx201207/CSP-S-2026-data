#include<bits/stdc++.h> 
using namespace std;
const int M=500069;
const int N=569;
vector<int> ask[N];
long long c,n,m,d,p,w[M],a[N],t[N][N],dp[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)dp[i][j]=2147483647;
	}
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(long long j=1;j<=x;j++){
			cin>>a[j]>>t[i][j];
			for(long long k=1;k<=j;k++){
				ask[a[j]].push(a[k]);
				ask[a[k]].push(a[j]);
			}
		}
	}
	
	for(long long i=1;i<=p;i++){
		long long x,y;
		cin>>x>>y;
		cout<<min(dp[x][y],dp[y][x]-);
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 
*/
