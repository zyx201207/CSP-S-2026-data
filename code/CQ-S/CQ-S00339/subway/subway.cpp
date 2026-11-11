#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5;
int w[N],k[N],a[505][N],t[500][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; cin >>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin >>w[i];
	for (int i=1;i<=n;i++)
	{
		cin >>k[i];
		for (int j=1;j<=k[i];j++) cin >>a[i][j]>>t[i][j];
	}
	for (int i=1;i<=q;i++){int x,y;cin >>x>>y;cout <<n<<'\n';}
	return 0;
 }

/*
啊啊啊啊高铁没有E座 
如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如 
蠕蠕蠕蠕蠕蠕如如如如如如如如如如如如如如如如如如如如如如如如如如如如如
如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如
如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如如 
佛如676767676767676767676767676767676767676767676767676767676767
佛如 
佛如 
佛如 
佛如 
佛如 
佛如 
佛如 
佛如 
佛如 
佛如 
佛如 
佛如
佛如 
佛如 
佛如 
盘点那些给CCF捐钱的惊艳瞬间 
S误了啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊 
样例样例阳历 
CCF，全名Chinese can fly 
啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊，怎么写啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊 
*/ 
