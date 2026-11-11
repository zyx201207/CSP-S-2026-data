//GZ-J00351 贵阳市双龙华麟学校 曾凡一 
#include<bits/stdc++.h>
using namespace std;
long long n,m,num[200005];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	sort(num+1,num+n+1,cmp);
	cout<<num[m];
	return 0;
}

