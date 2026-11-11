#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	int n1[10005];
	int a[10005];
	int b[10005];
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>n1[i];
	}

	
	sort(n1[0],n1[n-1]);
	for(int j=0;j<n;j++){
	for(int i=n-1;i>j+1;i--){
		a[i]=n1[n]-n1[i];
		if(a[i]<=m)
		b[i]=a[i];
	}
	}
	sort(b[0],b[n-1]);
	cout<<b[n-1];
	return 0;
} 
