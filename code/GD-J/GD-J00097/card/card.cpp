#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5; 
int a[maxn];
struct Node{
	int x,y;
};
vector<Node> vec;
int vis[maxn];
int pos[maxn];
int last[maxn];
long long ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=n;
		last[a[i]]=i;
	} 
	for(int i=n;i>=1;i--){
		if(vis[a[i]]){
			while(vec.back().x!=a[i]){
				Node u=vec.back();
				int x=u.x,y=u.y;
				vis[x]=0;
				last[x]=0;
				ans[x]+=pos[a[i]]-y;
				vec.pop_back();
			} 
			int x=vec.back().x;
			if(last[x]==0) last[x]=vec.back().y;
			vec.pop_back();
		}
		vec.push_back({a[i],i});
		vis[a[i]]=1;
		pos[a[i]]=i;
	}
	while(vec.size()!=0){ 
		Node u=vec.back();
		int x=u.x,y=u.y;
		ans[x]+=last[x];
		vec.pop_back();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
