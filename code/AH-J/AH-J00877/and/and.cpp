#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n, m;
int a[N];
int mx=-1;
int cnt=0;
int arr[N];
void x(int l,int k)
{
	if(k==m)
	{
		int an=1;
		for(int i=1;i<=m;i++)
		{
			an=an & arr[i];
		}
		mx=max(mx,an);
		arr[0]=1;
		fill(a+1,a+n+1,0);
	}
	arr[k+1]=a[l];
	x(l+1,k);
	x(l+1,k+1);
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int z=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		z=max(z,a[i]);
	}
	if(m==1)
	{
		cout<<z;
		return 0;
	}
	if(m==n)
	{
		int an=1;
		for(int i=1;i<=n;i++)
		{
			an=an&a[i];
		}
		cout<<an;
		return 0;
	}
	x(1,0);
	cout<<mx;
	return 0;
}
