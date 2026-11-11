#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
bitset<N> vis;
int n,m,a[N],b[N],top,ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]) vis[a[j]]=1,b[++top]=a[j];
			else while(b[top]!=a[j]) vis[b[top--]]=0;
		}
		for(int j=1;j<=top;j++) ++ans[b[j]];
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
 	return 0;
}
