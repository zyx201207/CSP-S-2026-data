#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int w[maxn],a[maxn],t[maxn],t2[maxn];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=m;i++) cin>>t2[i];
	cout<<w[1] + t[1] + (t[2] + t2[2]) + t2[3] + w[3];
	return 0;
}
