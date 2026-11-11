/**/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],d[500005],ans=0;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=0;
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[i]]=1;
				ans++;
				d[ans]=a[i];
			}
			else{
				for(int k=1;k<=ans;k++){
					if(d[k]==a[i]){
						for(int o=k;o<=ans;o++){
							c[d[o]]=0;
							d[o]=0;
						}
						ans=k-1;
						break;
					}
				}
			}
		}
		for(int j=1;j<=ans;j++) b[d[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
