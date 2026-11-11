/*
#include<bits/stdc++.h>
#define int int_fast64_t
using namespace std;
int w[int(5e5+5)],k[505],a[505][int(5e5+5)],t[505][int(5e5+5)];
int c,n,m,d,q,ans,minn=0x7fffffffffffffff;
void dfs(int u,int v,int tim){
	if(u==v)return minn=min(minn,tim),void();
	for(int i=1;i<=k[u];i++){
		for(int j=1;j<=n;j++){
			if(j!=u){
				for(int l=1;l<=k[j];l++){
					if(a[u][i]==a[j][l]){
						dfs(j,v,tim+t[u][i]+t[j][l]);
					}
				}
			}
		}
	}
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u==v){
			cout<<"0\n";
			continue;
		}
		ans=w[u]+w[v];
		set<int> st,ed;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==u)st.insert(i);
				if(a[i][j]==v)ed.insert(i);
			}
		}
		bool f=0;
		for(auto it:st){
			if(ed.count(it)){
				cout<<ans<<'\n';
				f=1;
				break;
			}
		}
		if(f)continue;
		minn=0x7fffffffffffffff;
		for(auto x:st){
			for(auto y:ed){
				dfs(x,y,0);
			}
		}
		cout<<ans+minn<<'\n';
	}
	return 0;
}
*/
#include<bits/stdc++.h>
#define int int_fast64_t
using namespace std;
int w[int(5e5+5)],k[505],a[505][int(5e5+5)],t[505][int(5e5+5)];
int c,n,m,d,q,ans;
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u==v){
			cout<<"0\n";
			continue;
		}
		ans=w[u]+w[v];
		set<int> st,ed;
		int jst,jed;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==u)st.insert(i),jst=j;
				if(a[i][j]==v)ed.insert(i),jed=i;
			}
		}
		bool f=0;
		for(auto it:st){
			if(ed.count(it)){
				cout<<ans<<'\n';
				f=1;
				break;
			}
		}
		if(f)continue;
		if(7<=c&&c<=11){
			int stt=*st.begin();
			int edd=*ed.begin();
			for(int i=1;i<=k[stt];i++){
				for(int j=1;j<=k[edd];j++){
					if(a[stt][i]==a[edd][j]){
						ans+=t[stt][i]+t[edd][j];
						break;
					}
				}
			}
			cout<<ans+t[stt][jst]+t[edd][jed]<<'\n';
			continue;
		}
//		cout<<"-\n";
	}
	return 0;
}
//---
