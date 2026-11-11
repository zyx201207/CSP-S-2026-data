/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=25;
const int mod1=621311e1+5;
const int mod2=336;
int c,n,m,d,q,minn=INT_MAX;
int k[N],w[N],t[N][N];
int a[N][N],x[N],y[N];
vector<int> g[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
/*	while(q--){
		cout<<26<<"\n";
	}*/
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++)
			g[w[i]].push_back(a[i][j]);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++)
			a[i][j]=w[i]; 
	}
	
	for(int i=1;i<=n;i++)
		a[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k>i||k>j) break;
				minn=min(minn,a[i][k]+a[j][k]);
			}
		}
	
	while(q--){
		cin>>x[q]>>y[q];
		w[q]=(x[q]+y[q]);
		cout<<a[x[q]][y[q]]<<"\n";
	}
	return 0;
}
