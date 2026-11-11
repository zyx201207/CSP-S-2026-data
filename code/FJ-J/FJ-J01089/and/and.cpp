#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sum=a[n];
	for(int i=n-m+1;i<n;i++){
		sum=int(sum&a[i]);
	}
	cout<<sum; 
}
