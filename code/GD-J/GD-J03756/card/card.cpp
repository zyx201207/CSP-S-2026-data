#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
#define ll long long
#define Endl "\n",void()
#define endl "\n"
#define End void()
namespace kong{bool st;}
const int N=5*1e5+7;
int n,m;
int a[N];
__gnu_cxx::rope<int> g[N],now;
int ans[N],vis[N],num[N];
int nxt[N],fa[N];
bool flag[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int lst=0;
	for(int i=n;i>=1;i--){
		if(flag[a[i]]!=0){
			vis[a[i]]++;
			now=g[a[i]];
			if(fa[a[i]]!=0){
				vis[a[i]]--;
				ans[a[i]]++;
				vis[fa[a[i]]]++;
			}
			lst=a[i];
		}else{
			flag[a[i]]=1;
			vis[a[i]]++;
			now.push_back(a[i]);
			if(fa[a[i]]!=0){
				vis[a[i]]--;
				ans[a[i]]++;
				vis[fa[a[i]]]++;
			}else{
				if(lst!=0){
					fa[a[i]]=lst;
					vis[a[i]]--;
					ans[a[i]]++;
					vis[fa[a[i]]]++;
				}
			}
			g[a[i]]=now;
			lst=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		if(fa[i]!=0&&vis[i]>0){
			ans[i]+=vis[i];
			vis[fa[i]]+=vis[i];
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(fa[i]!=0&&vis[i]>0){
			ans[i]+=vis[i];
			vis[fa[i]]+=vis[i];
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(fa[i]!=0&&vis[i]>0){
			ans[i]+=vis[i];
			vis[fa[i]]+=vis[i];
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[i]==0) continue;
		for(int u:g[i]){
			ans[u]+=vis[i];
		}
	}
	for(int i=1;i<=m-1;i++) cout<<ans[i]<<" ";
	return cout<<ans[m],End;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	cerr<<endl<<kong::MB()<<endl;
	return 0; 
} 
