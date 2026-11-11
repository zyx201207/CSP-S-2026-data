#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int main(){	
cin>>n>>m;
freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sum=a[i] and a[j];
		}
	}cout<<sum;
	}
