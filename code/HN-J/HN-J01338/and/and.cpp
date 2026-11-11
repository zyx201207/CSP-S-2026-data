#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int m,n;
int x;
int ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(m--){
		ans&=q.top();
		q.pop();
	}
	cout<<ans;
	return 0;
}
