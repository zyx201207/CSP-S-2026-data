#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=1;i<k;i++){
		ans&=a[n-1-i];
	}
	cout<<ans;
	return 0;
}
