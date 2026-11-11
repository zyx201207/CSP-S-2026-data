#include<bits/stdc++.h>
using namespace std;
int x[500010],y[300010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nn=n;
	for(int i=1;i<=n;i++) cin>>x[i];
	while(n--){
		int z[300010],j=1;
		for(int i=nn-n;i<=nn;i++){
			z[j]=x[i];
			for(int k=1;k<j;k++){
				if(z[k]==z[j]){
					j=k;
					break;
				}
			}
			j++;
		}
		for(int i=1;i<j;i++) y[z[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<y[i]<<' ';
	return 0;
}

