#include<bits/stdc++.h>
using namespace std;
int a[600000],m,p,n;
int mian(){
	freopen("ctrstal.in","r",stdin);
	freopen("ctrstal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]+1==m) p=a[i];
		}
	}
	cout<<p;
	return 0;	
}  

