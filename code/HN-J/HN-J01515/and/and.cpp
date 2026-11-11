#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long b=a[n];
	for(int i=2;i<=m;i++){
		b = b & a[n-i+1];
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
