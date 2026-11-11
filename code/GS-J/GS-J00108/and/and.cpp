#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long sum=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		sum&=a[i];
	}cout<<sum;
	return 0;
}
