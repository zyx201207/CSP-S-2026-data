//GZ-J00151 安顺市实验学校 罗子骏
#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
	return x>y;
}
long long n,m,a[20050];
long long s=0;
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else 
	{
		for(long long i=1;i<m;i++)
		{
			s=a[i]&a[i+1];
		}
	}
	cout<<s;
	
	
	return 0;
} 
