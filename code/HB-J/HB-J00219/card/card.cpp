#include<bits/stdc++.h>
using namespace std;
int n,m,a[3030],ans[3030],l[3030]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		int z=0;
		for(int f=i;f<=n;f++){
			for(int j=0;j<z;j++){
				if(l[j]==a[f]){
					for(int fr=j;fr<z;fr++)l[fr]=0;
					z=j;
				}
			}
			l[z++]=a[f];
		}
		for(int j=0;j<z;j++)ans[l[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
