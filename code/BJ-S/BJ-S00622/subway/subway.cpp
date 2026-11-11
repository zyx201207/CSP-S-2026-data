#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q;
vector<int> vec1[500005],vec2[500005],Vec1[505],Vec2[505];
int f[622][622];
int mat[622][622];
int vis[622];
int inq[622];
int w[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			vec1[a].push_back(i);
			vec2[a].push_back(t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1000000000000000000;
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec1[i].size();j++){
			for(int k=0;k<vec1[i].size();k++){
				if(j!=k)f[vec1[i][j]][vec1[i][k]]=min(f[vec1[i][j]][vec1[i][k]],vec2[i][j]+vec2[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]<1000000000000000000){
				Vec1[i].push_back(j);
				Vec2[i].push_back(f[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mat[i][j]=1000000000000000000;
		}
	}
	queue<int> pq;
	for(int i=1;i<=n;i++){
		memset(inq,0,sizeof inq);
		pq.push(i);
		vis[i]=i;mat[i][i]=0;inq[i]=1;
		while(!pq.empty()){
			int p_=pq.front();
			pq.pop();
			inq[p_]=0;
			for(int j=0;j<Vec1[p_].size();j++){
				if(mat[i][Vec1[p_][j]]>mat[i][p_]+Vec2[p_][j]){
					mat[i][Vec1[p_][j]]=mat[i][p_]+Vec2[p_][j];
					if(!inq[Vec1[p_][j]]){
						inq[Vec1[p_][j]]=1;
						pq.push(Vec1[p_][j]);
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1000000000000000000;
		for(int j=0;j<vec1[x].size();j++){
			for(int k=0;k<vec2[y].size();k++){
				ans=min(ans,mat[vec1[x][j]][vec1[y][k]]+vec2[x][j]+vec2[y][k]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
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
