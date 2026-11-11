#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m,a[10010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	long long sum=a[n];

	for(int i=n-1;i>=n-m;i++){
		sum=sum&a[i];
	}
	cout<<a[m];
	return 0;
}
