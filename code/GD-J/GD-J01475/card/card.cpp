#include<bits/stdc++.h>
using namespace std;
const int N=2e6;int n,m,t,a[N],ans[N],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		t++;
		int p=i;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=t) vis[a[j]]=t;
			else p=j;
		}
		for(int j=p;j<=n;j++) ans[a[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
