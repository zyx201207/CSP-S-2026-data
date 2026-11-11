#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q,w[500005],k[505],dis[5005][5005],ans[505][5005],o;
pair<int,int> pp[5005];
vector<int> a[505],t[505];
vector<pair<int,int>> xl[50005];
bool book[505][5005];
priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> qq;

void bfs(int x){
	memset(book,false,sizeof(book));
	qq.push({0,{0,x}});
	book[0][x]=true;
	while(!qq.empty()){
		pair<ll,pair<int,int>> p=qq.top();
		ll x1=p.second.first,x2=p.second.second,val=p.first;
		if(dis[x][ans[x1][x2]]==-1)
			dis[x][ans[x1][x2]]=val;
		else
			dis[x][ans[x1][x2]]=min(dis[x][ans[x1][x2]],val);
		qq.pop();
		if(x1==0){
			for(auto i:xl[x2]){
				int i1=i.first,i2=i.second;
				if(book[i1][i2] || i2==0) continue;
				book[i1][i2]=true;
				qq.push({val+t[i1][i2],{i1,i2}});
			}
		}else{
			if(!book[0][a[x1][x2]]){
				qq.push({val+t[x1][x2],{0,a[x1][x2]}});
				book[0][a[x1][x2]]=true;
			}
			for(int i=1,e=a[x1].size();i<e;i++){
				if(book[x1][i] || i==0) continue;
				book[x1][i]=true;
				qq.push({val,{x1,i}});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,-1,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans[0][i]=i;
		pp[i]={0,i};
	}
	o=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			ll aij,tij;
			cin>>aij>>tij;
			a[i].push_back(aij);
			t[i].push_back(tij);
			xl[aij].push_back({i,j});
			ans[i][j]=++o;
			pp[o]={i,j};
			for(int k=1;k<j;k++){
				dis[ans[i][j]][ans[i][k]]=0;
			}
		}
	}
	for(int i=1;i<=o;i++){
		bfs(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
