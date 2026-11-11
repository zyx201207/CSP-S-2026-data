#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int n,m,ma;
int a[N];
int f[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) 
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		f[1]=a[i];
		for(int j=i+1;j<n;j++)
		{
			for(int k=m;k>=2;k--)
				f[k]=max(f[k],f[k-1]&a[j]);
		}
		ma=max(ma,f[m]);
	}
	cout<<ma<<endl;
	return 0;
} 
