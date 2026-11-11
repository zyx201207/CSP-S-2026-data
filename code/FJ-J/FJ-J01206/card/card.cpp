#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500001],b[300001],c[500001],x;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		x=0;
		for(int j=i;j<n;j++){
			for(int k=0;k<x;k++){
				if(c[k]==a[j]){
					x=k;
					break;
				}
			}
			c[x++]=a[j];
		}
		for(int j=0;j<x;j++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
