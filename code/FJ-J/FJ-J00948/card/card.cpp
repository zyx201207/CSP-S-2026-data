#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[5000005],d[5000005],f[3000005]={0},x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			x++;
			d[x]=a[j];
			for(int k=1;k<x;k++){
				if(d[x]==d[k]){
					x=k;
				}
			}
		}
		for(int j=1;j<=x;j++){
		f[d[j]]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
