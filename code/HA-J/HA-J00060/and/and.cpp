#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,maxn,nu[200010];
bool vis[200010];
void dfs(int x,int y){
	if(x==n){
		if(y!=m)return;
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&cnt==1){
				ans&=nu[i];
			}else if(vis[i]&&cnt==0){
				ans=nu[i];
				cnt=1;
			}
		}
		maxn=max(maxn,ans);
		return;
	}
	vis[x+1]=1;
	dfs(x+1,y+1);
	vis[x+1]=0;
	dfs(x+1,y);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		nu[i]=read();
	}
	if(n<=20){
		dfs(0,0);
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ans=nu[1];
		for(int i=2;i<=n;i++){
			ans&=nu[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,nu[i]);
		}
		cout<<maxn;
		return 0;
	}
	cout<<0;
	return 0;
}