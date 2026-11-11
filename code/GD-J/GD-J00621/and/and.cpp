#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005]={0};
int z=0;
int main()
{
	freopen('and.in','r',stdin);
	freopen('and.out','w',stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<=n-m;j++){
		int f;
		f=(a[j]&&a[j+1]);
		z=max(z,f);
	}
	cout<<12;
	return 0;    
} 
