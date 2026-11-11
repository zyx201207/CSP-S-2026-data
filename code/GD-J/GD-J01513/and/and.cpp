#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=0;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
bool vis[N];
void dfs(int cnt,int cur){
	if(cnt==m){
		ans=max(ans,cur);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(cnt+1,cur&a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n<=20){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
		cout<<ans;
		return 0;
	}else if(n<=2000){
		if(m==1){
			int maxn=0;
			for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
			cout<<maxn;
			return 0;
		}else if(m==2){
			int maxn=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j)continue;
					maxn=max(maxn,a[i]&a[j]);
				}
			}
			cout<<maxn;
			return 0;
		}else if(m==n){
			int ans=a[1];
			for(int i=2;i<=n;i++)ans&=a[i];
			cout<<ans;
			return 0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
