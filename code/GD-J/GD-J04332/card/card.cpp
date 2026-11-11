#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,a[N];
int pre[N];
ll ans[N];
bool vis[N],flag=true;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<a[i-1]) flag=false;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				printf("%d ",i);
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++) pre[k]=0;
		for(int k=1;k<=n;k++) vis[k]=false;
		for(int j=i;j<=n;j++){
			if(!vis[pre[a[j]]]){
				for(int k=pre[a[j]];k<j;k++){
					if(vis[k]) continue;
					ans[a[k]]--;
					vis[k]=true;
				}
			}
			pre[a[j]]=j;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
