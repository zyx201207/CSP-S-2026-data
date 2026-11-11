#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int MAXN=500005;
int n,m;
int a[MAXN],b[300005],c[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				b[a[j]]=1;
			}else{
				for(int k=j-1;a[k]!=a[j];k--)
				{
					b[a[k]]=0;
				}
			}
		}
		for(int k=i;k<=n;k++)
		{
			if(b[a[k]]==1) c[a[k]]++;
			b[a[k]]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
