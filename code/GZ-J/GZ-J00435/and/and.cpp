#include<bits/stdc++.h>//李政轩 GZ-J00435 
using namespace std;
const int maxn = 1e6+325;
long long n,m;
int a[maxn];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m == 1)
	{
		cout<<a[n];
		return 0;
	}
	if(m == n)
	{
		cout<<a[1];
		return 0;
	}
	return 0;
} 
//思路：
