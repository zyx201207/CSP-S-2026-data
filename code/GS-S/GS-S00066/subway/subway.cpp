#include<bits/stdc++.h>
using namespace std;
const int MAXN=500;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	int c,n,m,d,q,k;
	int w[MAXN];
	int line[MAXN][MAXN]; 
	int t[MAXN][MAXN]; 
	int plan[MAXN][2];
	int dis[MAXN][MAXN];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++)cin>>line[i][j]>>t[i][j];
	}
	for(int i=0;i<q;i++){
		cin>>plan[i][0]>>plan[i][1];
	}
	return 0;
} 
