//GZ-J00543 贵阳市第十八中学 王相宇  
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000010],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n];
	else
	{
		maxn=a[n];
		for(int i=1;i<m;i++)
		{
			long long qwq=maxn;
			maxn=qwq&a[n-i];
		}
	}
	cout<<maxn;
	return 0;
}
    
