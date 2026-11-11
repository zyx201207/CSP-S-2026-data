#include <bits/stdc++.h>//完了，/和\分不清了 
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=2e5+10;
int n,m;
ll a[N],f[N];
bool st[N];
int main()
{
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>1;j--)
			f[j]=max(f[j],f[j-1]&a[i]);
		f[1]=max(f[1],a[i]);
	}
//	for(int j=1;j<=m;j++) cout<<f[j]<<"\n";
	cout<<f[m];
	return 0;
 }
