#include<bits/stdc++.h>
using namespace std;
long long ma,a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	ma=-11111;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	cout<<a[n/2];
	return 0;
}
