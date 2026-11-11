#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,k,ans;
int m[N];
int a[N];
int fa[N];
int d[N];
vector<int> son[N];


int Find(int x){
	if(fa[x]!=x) return fa[x]=Find(fa[x]);
	return x;
}

void check(){
	for(int i=1;i<=k;i++){
		fa[a[i]]=a[i];
		for(int j=1;j<i;j++) if(m[a[i]]==a[j]) fa[a[i]]=a[j]; 
//		cout<<a[i]<<" "<<fa[a[i]]<<"\n";
	}
	
	int x=-1,y=-1;
	for(int i=1;i<=k;i++){
		if(x!=Find(a[i])&&x!=-1){
			if(y!=fa[a[i]]&&y!=-1){
//				cout<<1<<"\n";			
				return;
			}else{
				y=fa[a[i]];
			}
		}else{
			x=fa[a[i]];
		}
	}
//	cout<<"#"<<"\n";
	int res=0;
	for(int i=1;i<=n;i++){
		int xxx=1e18;
		if(fa[i]==x||fa[i]==y)continue;
		for(int j=1;j<=k;j++){ 
//			cout<<i<<" "<<j<<"\n";
			int xx=i,yy=a[j];
			if(d[xx]>d[yy]) swap(xx,yy);
			int sum=0;
			while(d[xx]<d[yy]){
//				cout<<yy<<"\n";
				sum++,yy=m[yy];
			}
			while(xx!=yy){
				sum+=2;
				xx=m[xx],yy=m[yy];
//				cout<<xx<<" "<<yy<<"\n";
			}
			xxx=min(xxx,sum);
//			cout<<sum<<"~\n";
		}
		res=max(res,xxx);
	}
	ans=min(ans,res);
//	cout<<"~"<<"\n";
}

void dfs(int l,int p){
	if(l>k){
		check();
//		cout<<1<<"\n";
		return;
	}
	
	for(int i=p+1;i<=n;i++){
		a[l]=i;
//		cout<<i<<"\n";
		dfs(l+1,i);
	}
}

void build(int u,int l){
//	cout<<u<<" ";
	d[u]=l;
	for(int i=0;i<son[u].size();i++){
		build(son[u][i],l+1);
	}
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) son[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		m[v]=u;
		son[u].push_back(v);
	}
	ans=1e18;
	build(1,1);
	dfs(1,0);
	cout<<ans<<"\n";
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1,CCC;
	cin>>CCC>>TTT;
	while(TTT--){
		solve();
	}
}