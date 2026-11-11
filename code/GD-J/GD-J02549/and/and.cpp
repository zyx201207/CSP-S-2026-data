#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=a[n-1];
	for(long long i=1;i<m;i++){
		ans=ans&a[n-1-i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
