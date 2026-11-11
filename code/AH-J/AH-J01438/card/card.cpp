#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],b[1005];
int z=1;
int ans[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int t=1;t<=n;t++){
		z=t;
		for(int i=t;i<=n;i++){
			a[z]=b[i];
			z++;
			for(int j=t;j<z-1;j++){
				if(a[j]==a[z-1]){
					a[j]=b[i];
					for(int x=j+1;x<z;x++){
						a[x]=0;
					}
					z=j+1;
				}
			}
		}
		for(int i=t;i<=n;i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
