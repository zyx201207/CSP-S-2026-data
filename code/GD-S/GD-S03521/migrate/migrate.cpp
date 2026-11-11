#include<bits/stdc++.h>
using namespace std;
int a[600000],m,n;
int mian(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]>a[j]) cout<<m; 
		}
	}
	return 0;	
}  

