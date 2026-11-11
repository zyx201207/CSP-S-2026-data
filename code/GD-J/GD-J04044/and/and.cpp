#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=a[n];
	for(int i=n-1;i>=1+n-m;i--){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
} 
