#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int walk[500005];
int he[502],w[300005],e[300005],nxt[300005],cnt;
void addedge(int u,int v,int x){
	e[++cnt]=v,w[cnt]=x,nxt[cnt]=he[u],he[u]=cnt;
}
vector<pair<int,int> >line[502],hav[500005];
int dis[502][502];
bool book[502];
struct node{
	int poi,dis;
	node(int x,int y){poi=x,dis=y;}
	bool operator < (const node x)const{
		return dis>x.dis;
	}
};
void dijkstra(int sta,int dis[]){
	memset(book,false,sizeof(book));
	priority_queue<node>q;
	q.push(node(sta,0)),dis[sta]=0;
	while(!q.empty()){
		int pos=q.top().poi;
		q.pop();
		if(book[pos]) continue;
		book[pos]=true;
		for(int i=he[pos];~i;i=nxt[i]){
			if(dis[e[i]]>dis[pos]+w[i]){
				dis[e[i]]=dis[pos]+w[i];
				q.push(node(e[i],dis[e[i]]));
			}
		}
	}
}
int tmp[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(he,-1,sizeof(he));
	for(int i=1;i<=m;i++){
		cin>>walk[i];
	}
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		while(len--){
			int a,t;
			cin>>a>>t;
			line[i].push_back(make_pair(a,t));
			hav[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++) tmp[j]=0;
		for(pair<int,int> sta:line[i]) tmp[sta.first]=sta.second;
		for(int j=i+1;j<=n;j++){
			int val=LLONG_MAX;
//			cout<<"TRY "<<i<<" "<<j<<'\n';
			for(pair<int,int> sta:line[j]){
				if(tmp[sta.first]) val=min(val,tmp[sta.first]+sta.second);
//				cout<<sta.first<<" "<<sta.second<<' '<<tmp[sta.first]<<'\n';
			}
			if(val!=LLONG_MAX) addedge(i,j,val),addedge(j,i,val);//,cout<<i<<' '<<j<<' '<<val<<'\n';
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dijkstra(i,dis[i]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=LLONG_MAX;
		for(pair<int,int> st:hav[x]){
			for(pair<int,int> ed:hav[y]){
				ans=min(ans,walk[x]+walk[y]+st.second+ed.second+dis[st.first][ed.first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
