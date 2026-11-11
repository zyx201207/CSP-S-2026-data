#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdin);
	int n,m;
	cin>>n>>m;
	int a[500001]={},b[300001]={},c[500001]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[j]=a[j];
			for(int z=i;z<j;z++){
				if(c[z]==c[j]){
					for(int x=z;x<j;x++){
						c[x]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(c[j]>0){
				b[c[j]]++;
				c[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	freclose("r","card.in",stdout);
	freclose("w","card.out",stdout);
}
