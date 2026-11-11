#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],cnt;
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int i=1;i<=n;i++){
		cnt=1;
		memset(vis,0,sizeof(vis));
		int s[N]={0};
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				s[cnt]=a[j];
			}else {
				for(int k=i;k<=n;k++) if(s[k]==a[j]){
					for(int l=k+1;l<=n;l++) {s[l]=0;vis[s[l]]=0;cnt=k+1;}
				}
			}
		}
		for(int j=1;j<i;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				s[cnt]=a[j];
			}else {
				for(int k=1;k<i;k++) {
					if(s[k]==a[j]) for(int l=k+1;l<i;l++) {s[l]=0;vis[s[l]]=0;cnt=k+1;}
				}
			}
		}
		for(int j=1;j<=m;j++) {
			b[s[j]]++;
		}
		cout<<endl;
	}for(int i=1;i<=m;i++) printf("%d ",b[i]);
	return 0;
}
