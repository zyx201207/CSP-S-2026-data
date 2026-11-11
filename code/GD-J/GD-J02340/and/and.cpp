#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int a[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
