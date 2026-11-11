#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n],max1=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	} 
	cout<<max1;
	return 0;
} 
