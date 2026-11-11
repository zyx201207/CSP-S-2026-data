#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,cnt,q[500005],t[500005],a[500005];
bool b;
signed main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	for (int i=1;i<=300005;i++)q[i]=q[i-1]+t[i];
	for (int i=1;i<=m;i++)cout<<q[a[i]]<<" ";
	return 0;
}
