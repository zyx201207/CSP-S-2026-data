#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5;
int n,m,maxn=INT_MIN;
int a[MAXN];
void f(int d,int id,int sum)
{
	if(d==m+1)
	{
		if(sum>maxn) maxn=sum;
		return;
	}
	for(int i=id;i<=n;i++)
	{
		f(d+1,id+1,sum&a[i]);
	} 
}
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n-m+1;i++)
	{
		f(1,i+1,a[i]);
	}
	cout << maxn;
}
