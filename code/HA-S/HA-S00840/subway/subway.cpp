#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> PII;
int c,n,m,df,qu;
long long w[500010],dis[510010],s[510010],t[510010];
vector<long long> d[510010],g[510010];
vector<long long> ans[510010];
void dij(int x){
	memset(dis,0x3f,sizeof dis);
	memset(s,0,sizeof s);
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,x});
	
	while(!q.empty()){
		PII f=q.top();
		long long di=f.first,y=f.second;
		
		q.pop();
		if(s[y]){
			continue;
		}
		s[y]=1;
		for(int i=0;i<d[y].size();i++){
			if(di+g[y][i]<dis[d[y][i]]){
				dis[d[y][i]]=di+g[y][i];
				q.push({dis[d[y][i]],d[y][i]});
			}
		}
	}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>df>>qu;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			d[m+i].push_back(a);
			d[a].push_back(m+i);
			g[m+i].push_back(t);
			g[a].push_back(t);
		}
	}

	for(int i=1;i<=qu;i++){
		int x,y;
		cin>>x>>y;
		if(!t[x]){
			t[x]=1;
			dij(x);
			for(int i=1;i<=n+m;i++){
				ans[x].push_back(dis[i]);
			}
		}
		cout<<w[x]+ans[x][y-1]+w[y]<<endl;
	}
	return 0;
}

