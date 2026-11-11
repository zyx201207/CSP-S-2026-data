#include<bits/stdc++.h>
using namespace std;
int w[500010],len[500010],d[500010];
long long e[500010];
bool f[500010];
struct node{
	int x;
	long long value;
	bool operator < (const node&x) const {
		return x.value<value;
	};
};
node c[500010][30];
vector<node>v[510];
priority_queue<node>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a914,n,m,d2,q2;
	cin>>a914>>n>>m>>d2>>q2;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			int x2,y;
			cin>>x2>>y;
			v[i].push_back({x2,y});
			d[x2]++;
			c[x2][d[x2]]={i,j};
		}
	}
	//cout<<v[c[3][1].x][c[3][1].value].value<<endl;
	//cout<<v[c[1][1].x][c[1][1].value-1].value<<" "<<c[1][1].value<<endl;
	while(q2--){
		int x2,y;
		cin>>x2>>y;
		q.push({x2,0});
		for(int i=1;i<=m;i++)
			e[i]=1e9,f[i]=0;
		e[x2]=0;
		while(!q.empty()){
			node a=q.top();
			q.pop();
			for(int i=1;i<=d[a.x];i++){
				for(int j=0;j<len[c[a.x][i].x];j++){
					if(v[c[a.x][i].x][j].x!=a.x){
						if(e[v[c[a.x][i].x][j].x]>e[a.x]+v[c[a.x][i].x][j].value+v[c[a.x][i].x][c[a.x][i].value-1].value){
							e[v[c[a.x][i].x][j].x]=e[a.x]+v[c[a.x][i].x][j].value+v[c[a.x][i].x][c[a.x][i].value-1].value;
							if(!f[v[c[a.x][i].x][j].x]&&d[v[c[a.x][i].x][j].x]>1)
								q.push({v[c[a.x][i].x][j].x,e[v[c[a.x][i].x][j].x]}),f[v[c[a.x][i].x][j].x]=1;
						}
					}
				}
			}
		}
		cout<<e[y]+w[x2]+w[y]<<endl;
	}
	return 0;
}
