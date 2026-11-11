#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=a[n-1]&a[n-2];
	for(int i=n-3;i>=n-m;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
