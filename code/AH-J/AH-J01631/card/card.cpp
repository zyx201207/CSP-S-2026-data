#include<bits/stdc++.h>
using namespace std;
int n,m,a[50001],h=0,b[50001],c[30001]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		h=0;
		for(int j=i;j<=n;j++){
		    b[++h]=a[j];
		    int z=1;
		    while(z<h){
		    	if(b[z]==b[h])h=z;
		    	z++;
			}
			
	    }
	    for(int j=1;j<=h;j++){
	    	c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
