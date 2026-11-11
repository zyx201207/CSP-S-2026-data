#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n;
	cin>>m>>n;
	long long x[m],big[n];
	for(int i=0;i<m;i++){
		cin>>x[i];
	}
	for(int i=0;i<n;i++){
		for(int l=0;l<n-i;l++){
			if(x[l]<x[l+1]){
				x[l+1]=x[l];
			}
		}
	}
	long long a=x[m-1];
	for(int i=m-2;i>m-n-1;i--){
		a|=x[i];
	}
	cout<<a<<"\n";
	return 0;
} 
