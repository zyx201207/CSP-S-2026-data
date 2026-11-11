#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=510;
const int Q=1e5+10;
int c,n,m,d,q;
int w[N];
int b[N];
vector<pair<int,int> > ed[M];//point time
vector<pair<int,int> > tu[N];//path time
void outb(){
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	cout<<"\n";
}
int bfs(int x,int y){
	queue<int> qu;
	memset(b,-1,sizeof(b));
	qu.push(x);
	b[x]=0;
	while(!qu.empty()){
		for(int i=0;i<tu[qu.front()].size();i++){
			for(int j=0;j<ed[ tu[qu.front()][i].first ].size();j++){
				pair<int,int> next=ed[ tu[qu.front()][i].first ][j];
				if(b[next.first]==-1||b[qu.front()]+tu[qu.front()][i].second+next.second<b[next.first]){
					b[next.first]=tu[qu.front()][i].second+next.second+b[qu.front()];
					qu.push(next.first);
				}
//				cout<<qu.front()<<" "<<next.first<<":";
//				outb();
			}
		}
		qu.pop();
	}
	return b[y];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			pair<int,int> tmp;
			tmp.first=i;
			tmp.second=t;
			tu[x].push_back(tmp);
			tmp.first=x;
			ed[i].push_back(tmp);
		}
	}
	if(c==21||c==22){
		int po,minw=INT_MAX;
		for(int i=1;i<=m;i++){
			if(tu[ed[i][0].first].size()==2){
				if(tu[ed[i][0].first][0].first!=i)
					minw=min(minw,ed[i][0].second+tu[ed[i][0].first][0].second);
				else
					minw=min(minw,ed[i][0].second+tu[ed[i][0].first][1].second);
			}
		}
		for(int k=1;k<=q;k++){
			int x,y;
			cin>>x>>y;
			
			if(tu[x].size()==2&&tu[y].size()!=2){
				int i;
				for(i=0;i<ed[tu[y][0].first].size();i++){
					if(ed[tu[y][0].first][i].first==x)break;
				}
				cout<<w[x]+w[y]+tu[y][0].second+ed[tu[y][0].first][i].second<<"\n";
				continue;
			}
			else if(tu[y].size()==2&&tu[x].size()!=2){
				int i;
				for(i=0;i<ed[tu[x][0].first].size();i++){
					if(ed[tu[x][0].first][i].first==y)break;
				}
				cout<<w[x]+w[y]+tu[x][0].second+ed[tu[x][0].first][i].second<<"\n";
				continue;
			}
			else if(tu[y].size()==2&&tu[x].size()==2){
				int i;
				for(i=0;i<ed[1].size();i++){
					if(ed[1][i].first==y)break;
				}
				int j;
				for(j=0;j<ed[1].size();j++){
					if(ed[1][j].first==x)break;
				}
				int minn=w[x]+w[y]+ed[1][j].second+ed[1][i].second;
				for(i=0;i<ed[2].size();i++){
					if(ed[2][i].first==y)break;
				}
				for(j=0;j<ed[2].size();j++){
					if(ed[2][j].first==x)break;
				}
				minn=min(minn,w[x]+w[y]+ed[1][j].second+ed[1][i].second);
				cout<<minn<<"\n";
				continue;
			}
			else{
				cout<<w[x]+w[y]+tu[x][0].second+tu[y][0].second+minw<<"\n";
				continue;
			}
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+bfs(x,y)+w[y]<<"\n";
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
