#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int c[m];
	int a[n];
	int b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int i=0;i<m;i++){
			c[i]=0;
	}
		for(int j=i;j<n;j++){
			b[j]=a[j];
			for(int k=0;k<j;k++){
				if(b[k]==b[j]){
					for(int p=k;p<j;p++){
						b[p]=0;
					}
				}}
			for(int k=j;k<n;k++){
				c[b[i]]++;
			}
}}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
}}
