#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn],n,m,ans;
bool check(int x){
	int cnt=0;
	for (int i=1;i<=x-1;i++) cnt+=a[x]-a[i];
	if (cnt<=m) return 1;
	else return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort (a+1,a+n+1);
    int l=1,r=n;
    while(l<=r){
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
    return 0;
}
