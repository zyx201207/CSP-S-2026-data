#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	char b[n];
	char dcl[1005];
	int xb=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			dcl[xb]=b[i];
			xb++;
		}
	}
	int ans=0;
	for(int i=0;i<xb/2;i++){
		if(dcl[i]!=dcl[xb-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
