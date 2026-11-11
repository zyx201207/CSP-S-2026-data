#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5*1e5+5;
int n,m,a[MAXN],ans[MAXN];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
