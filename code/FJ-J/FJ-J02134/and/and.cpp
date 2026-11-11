#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2e5+5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f&&a[i]!=i-1)f=0;
	}
	if(f){
		cout<<0;return 0;
	}
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=n;i>n-m;i--)ans&=a[i];
	cout<<ans;
	return 0;
}

