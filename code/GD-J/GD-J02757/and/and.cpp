#include <bits/stdc++.h>
using namespace std;
int a[10005],s[10005];
bool shu(int a ,int b)
{
	if(a%b==0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	int n ,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int cnt =0;
	for(int i=1;i<n;i++)
	{
		if(shu(a[i],a[i+1])!=0)
		{
			cout << a[i];
			cnt++;
		}
	}
	if(cnt==0)
	{
		cout << 0;
	}
	return 0;
}
