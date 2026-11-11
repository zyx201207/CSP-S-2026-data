#include<bits/stdc++.h>
using namespace std;
long long m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n/2;i--){
		if(a[i]-a[i-1]>a[i-1]-a[i-2]){
			a[n-m+1]=a[n-2];
		}
	}
	cout<<a[n-m+1];
	return 0;
}
