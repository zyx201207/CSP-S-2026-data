#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m;
set<int>a;
signed main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		a.insert(l);
	}
	n=a.size();
	
	int ans;
	ans=a[int(n-1)];
	for(int i=1;i<m;i++){
		ans=ans&a[n-1-i];
	}
	cout<<ans;
	return 0;
}
