#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int b[100000];
int c[1000000],d[1000000];
int main(){ 
//	freopen("in.card","r",stdin);
//	freopen("out.card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=a[i];
		for(int j=1;j<i;j++){
			if(d[j]==d[i]){
				d[j]=d[i];
			}
		} 
		for(int g=1;g<=n;g++){
			if(d[g]!=0){
				c[d[g]]++;
			}
		}
	} 
	for(int g=1;g<=n;g++){
			if(d[g]!=0){
				cout<<d[g]<<" ";
			}
		}	

	return 0;
} 
