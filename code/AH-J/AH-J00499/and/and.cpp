#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m,a[100100],da=-99999;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++){
		if(a[i]|a[i+1]>da)
		da=a[i]|a[i+1];
	}
	cout<<da;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
