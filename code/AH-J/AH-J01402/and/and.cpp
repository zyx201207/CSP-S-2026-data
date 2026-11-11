#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
int n,m;
ll a[N],b[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) b[i]=a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=m;j++) b[i]=b[j]&b[j+1];
	}
	sort(b,b+n,cmp);
	cout<<b[0];
	return 0;
}
