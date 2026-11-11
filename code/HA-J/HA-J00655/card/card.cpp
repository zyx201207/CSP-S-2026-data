#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ans[N],k[N];
int p[N],tot;
bool vis[N],vis2[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		k[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		tot=0;
		if(!vis[a[i]]){
			vis[a[i]]=1;
			for(int j=i;j<=n;j++){
				while(vis2[a[j]]&&tot>0&&a[j]!=a[p[tot]]){
					vis2[a[p[tot]]]=0;
					tot--;
				}
				if(a[j]==a[p[tot]]){
					vis2[a[p[tot]]]=0;
					tot--;
				}
				p[++tot]=j;
				vis2[a[p[tot]]]=1;
			}
			for(int j=i;j<=n;j++){
				vis2[a[j]]=0;
			}
			for(int j=1;j<=tot;j++){
				ans[a[p[j]]]+=k[a[i]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
