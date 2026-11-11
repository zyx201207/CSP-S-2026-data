#include<bits/stdc++.h>
using namespace std;
int m,n,a[500001],b[300001],x,c[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int i=0;i<n;i++){
			c[i]=a[i]
		}
		for(int k=i;k<m;k++){
			if(c[i]==c[k]){
				c.clear(i,k-i);
			}
		}
		for(int j=0;j<m;j++){
			b[c[j]]++;
		}
	}
	for(int i=0;i<=m;i++){
		if(b[i]!=0){
			cout<<b[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
