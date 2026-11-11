#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],x,y;
vector<int>a[505],t[505],s[505],vec[500005];
int BFS(int x,int su){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	int v[500005]={0};
	v[x]=1;
	q.push({x,su});
	while(q.size()){
		x=q.top().first,su=q.top().second;
//		cout<<x<<" "<<su<<endl;
		q.pop();
		for(int i=0;i<vec[x].size();i++){
			int p=find(a[vec[x][i]].begin()+1,a[vec[x][i]].end()+1,x)-a[vec[x][i]].begin();
			for(int j=1;j<p;j++){
				if(!v[a[vec[x][i]][j]]){
//					cout<<a[vec[x][i]][j]<<" "<<su+s[vec[x][i]][p]-s[vec[x][i]][j-1]<<endl;
					if(a[vec[x][i]][j]==y){
						return su+s[vec[x][i]][p]-s[vec[x][i]][j-1];
					}v[a[vec[x][i]][j]]=1;
					q.push({a[vec[x][i]][j],su+s[vec[x][i]][p]-s[vec[x][i]][j-1]});
				}
			}for(int j=p+1;j<=k[vec[x][i]];j++){
				if(!v[a[vec[x][i]][j]]){
//					cout<<a[vec[x][i]][j]<<" "<<su+s[vec[x][i]][j]-s[vec[x][i]][p-1]<<endl;
					if(a[vec[x][i]][j]==y){
						return su+s[vec[x][i]][j]-s[vec[x][i]][p-1];
					}v[a[vec[x][i]][j]]=1;
					q.push({a[vec[x][i]][j],su+s[vec[x][i]][j]-s[vec[x][i]][p-1]});
				}
			}
		}
	}
}signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0),t[i].push_back(0),s[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			cin>>x;
			vec[x].push_back(i);
			a[i].push_back(x);
			cin>>x;
			t[i].push_back(x);
			s[i].push_back(s[i][j-1]+x);
		}
	}while(q--){
		cin>>x>>y;
		cout<<BFS(x,0)+w[x]+w[y]<<endl;
	}
}
