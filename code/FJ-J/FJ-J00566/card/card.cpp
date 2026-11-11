#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000],b[500000],c[300000]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){	
		int j=i;
		while(j<=n){
			b[j]=a[j];
			for(int k=i;k<j;k++){
				if(b[k]==b[j]){
					j=k-1;
				}
			}
			j++;
		}
		for(int k=1;k<=j;k++){
			if(b[k]==i){
				c[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0; 
}
