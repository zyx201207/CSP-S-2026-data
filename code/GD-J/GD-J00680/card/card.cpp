#\
i\
n\
c\
l\
u\
d\
e\
 \
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
#define int long long
using namespace std;

int n,m,a[500002],to[500002];
int nxt[500002],siz[500002];
int ans[500002];
vector<int>G[500002];
void dfs(int u){
	siz[u]=1;
	for(int i=0;i<G[u].size();i++){
		dfs(G[u][i]);
		siz[u]+=siz[G[u][i]];
	}
//	cerr<<u<<" "<<siz[u]<<" "<<to[u]<<"\n";
	if(u!=n+1){
		ans[a[u]]+=siz[u];
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("card6.in","r",stdin);
//	freopen("card6.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!nxt[a[i]])nxt[a[i]]=i;
		to[i]=nxt[a[i]]+1;
	}
	for(int i=1;i<=n;i++){
		G[to[i]].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	akioi;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

10 3
1 1 1 2 2 3 3 1 2 3
*/
