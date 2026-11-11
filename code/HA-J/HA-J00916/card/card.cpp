#include<bits/stdc++.h>
using namespace std;
int n,m,t[300005],a[500005],pos=0,z[500005],k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=n;o++){
		k=0;
		memset(z,0,sizeof(z));
		pos++;
		for(int i=pos;i<=n;i++){
			k++;
			z[k]=a[i];
			for(int j=1;j<=k;j++){
				if(z[j]==a[i]){
					k=j;
					z[k]=a[i];
				}
			}
		}
		for(int i=1;i<=k;i++){
			t[z[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
