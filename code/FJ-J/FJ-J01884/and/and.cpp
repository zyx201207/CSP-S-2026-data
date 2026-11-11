#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and5.in","r",stdin);
	freopen("and5.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=a[n-1];
	for(int i=n-2;i>=n-m;i--) sum=(sum&a[i]);
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
