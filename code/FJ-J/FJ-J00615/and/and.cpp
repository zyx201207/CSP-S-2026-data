#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,z=0,a[9999];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1])z=a[i-1];
		else z=a[i]; 
	}
	cout<<z;
	return 0;
}


