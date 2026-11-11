#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
