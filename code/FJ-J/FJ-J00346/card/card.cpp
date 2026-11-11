#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int x=i;x<j;x++){
				if(k==1){
					a[x]=0;
				}
				if(a[x]==a[j]&&a[x]!=0){
					a[x]=0;
					k=1;
				}
			}
			k=0;
		}
		for(int u=1;u<=m;u++){
			for(int j=i;j<=n;j++){
				if(a[j]==u){
					b[u]++;
					break;
				}
			}
		}
		for(int u=1;u<=n;u++){
			a[u]=c[u];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
