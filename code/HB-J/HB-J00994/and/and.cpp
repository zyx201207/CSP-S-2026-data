#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 
    int a[200050]={};
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=a[1];

	for(int i=1;i<=m;i++){
		k=k&a[i];
	}
 cout<<k;
	
	
		
	return 0;
}

