#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define fford(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define inf 1e15
using namespace std;
const int N=1e5+5;

int c,t,n,k,ans,dep[N];
vector<int> v;

vector<int> to[N];
void addEdge(int x,int y){
	to[x].push_back(y);
	to[y].push_back(x);
} 

bool vis[N];
void dfs2(int root){
	vis[root]=true;
	for(const auto x:to[root]){
		ffor(i,0,k-1){
			if(v[i]==x){
				if(!vis[x]) dfs2(x);
				break;
			}
		}
	}
}

void dfs(int root,int fa){
	dep[root]=dep[fa]+1;
	for(const auto x:to[root]){
		if(x!=fa) dfs(x,root);
	}
}

bool used[N];
void search2(int cnt){
	cout<<"!!! "<<cnt<<endl;
	if(cnt==k){
		ffor(i,1,n) vis[i]=false;
		int cnt2=0;
		ffor(i,0,k-1){
			if(!vis[v[i]]){
				cnt++;dfs2(v[i]);
			}
		}
		if(cnt2>2) return;
		int tmp=-inf;
		ffor(i,1,n){
			int tmp2=inf;
			ffor(i,1,n) dep[i]=0;
			dfs(i,0);
			ffor(i,0,k-1){
				tmp2=min(tmp2,dep[v[i]]-1);
			}
			tmp=max(tmp,tmp2);
		}
		ans=min(ans,tmp);
		return;
	}
	ffor(i,1,n){
		if(!used[i]){
			v.push_back(i);
			used[i]=true;
			search2(i+1);
			v.pop_back();
			used[i]=false;
		}
	}
}

void solve(){
	cin>>n>>k;int x,y;ans=inf;
	ffor(i,1,n) to[i].clear();
	ffor(i,1,n-1){
		cin>>x>>y;
		addEdge(x,y);
	}
	search2(0);
	cout<<ans<<endl;
}

signed main(){
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--) solve();
	return 0;
}

