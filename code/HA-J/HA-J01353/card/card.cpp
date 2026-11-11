#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;int a[n+5],c[n+5];int b[m+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		b[i]=0;
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(c[i]==c[j]){
					for(int k=i;k<=j;k++){
						c[i]=0;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			b[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
