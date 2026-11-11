#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],p[500005],pos[500005],vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000||m<=2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) pos[j]=p[j]=0;
			for(int j=i;j<=n;j++){
				vis[j]=0;
				p[a[j]]++;
				if(pos[a[j]]) for(int k=pos[a[j]];k<j;k++) if(!vis[k]){
					p[a[k]]--;
					pos[a[k]]=0;
					vis[k]=1;
				}
				pos[a[j]]=j;
			}
			for(int j=1;j<=m;j++) ans[j]+=(p[j]);
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	for(int i=1;i<=n;i++) ans[a[i]]++;
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
//I love you,gsy
