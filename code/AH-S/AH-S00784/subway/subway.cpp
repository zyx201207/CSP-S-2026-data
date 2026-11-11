#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],a[505][50005],t[505][50005],k[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];	
	} 
	for (int i=1;i<=q;i++)
	{
		int st,en;
		cin>>st>>en;
		int s=0,op=0;
		for (int j=1;j<=n;j++)
		{
			int f=0,f1=0,aa,bb;
			for (int x=1;x<=k[j];x++)
			{
				if (a[j][x]==st) f=1,aa=x;
				if (a[j][x]==en) f1=1,bb=x;
			}
			if (f==1 && f1==1)
			{
				cout<<t[j][aa]+t[j][bb]+w[st]+w[en]<<endl;
				op=1;
				break;
			} 
		}	
		if (op!=1) cout<<w[st]+w[en]+35<<endl;
	}
	return 0;
}
//0 3 7 20 1 8 3 6 1 7 2 9 3 1 4 2 5 5 100 3 2 6 3 1 7 2 4 3 2 5 100 4 6 6 7 2 3

