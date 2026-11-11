#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200005],ap;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ap=a[n-1];
	for(int i=n-1;i>=n-m;i--){
		ap=ap&a[i];
	}
	cout<<ap;
	return 0;
}
