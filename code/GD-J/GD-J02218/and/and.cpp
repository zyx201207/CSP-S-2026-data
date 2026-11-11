#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+7;
int a[N];
int n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	long long  ans=a[0];
	for (int i=1;i<m;i++) 
	{
		ans &= a[i];
	}
	cout<<ans;
}
