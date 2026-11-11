#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int ands(int x,int y)
{
	return x&y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int maxn=-1,sum;
	for(int i=0;i<m;i++)
	{
		for(int i=0;i<n;i++)
		{
			int b=a[i+i];
			sum=ands(sum,b);
		}
		maxn=max(sum,maxn);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
