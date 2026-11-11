#include<bits/stdc++.h>
using namespace std;
#define maxn 500005

int c,n,m,d,q,a[maxn];
long long e[1005][1005],w[1005][1005],ans=9e18;
vector<pair<int,int> > v[maxn];

int main(){
	memset(e,0x3f,sizeof e);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		e[i][i]=0;
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	
	for(int i=1;i<=m;i++){
		for(auto j:v[i]){
			for(auto k:v[i]){
				if(j==k) continue;
				int u=j.first;
				int v=k.first;
				e[u][v]=min(e[u][v],(long long)j.second+k.second);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=9e18;
		for(auto j:v[x]){
			for(auto k:v[y]){
				ans=min(ans,e[j.first][k.first]+j.second+k.second);
			} 
		}
		cout<<ans+a[x]+a[y]<<endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

fc.exe D:\GD-S00436\subway\subway.out D:\GD-S00436\subway\subway7.ans
*/
