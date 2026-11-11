#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int cx[500010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int z[500010]={0},d=1;
		for(int j=i;j<=n;j++){
			for(int o=1;o<=n;o++)
			if(z[o]==a[j]){
				for(int t=o;t<=n;t++)z[t]=0;
				d=o;
				break;
			}
			z[d]=a[j];
			d++;
		}
		for(int j=1;j<=n;j++)cx[z[j]]++;
	}
	for(int j=1;j<=m;j++)cout<<cx[j]<<" ";
	return 0;
}

