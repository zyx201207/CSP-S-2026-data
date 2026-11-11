#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int t;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	t=n-1;
	while(m--){
		ans&=a[t];
		t--;
	}
	cout<<ans;
	return 0;
} 
