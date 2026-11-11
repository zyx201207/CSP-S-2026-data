#include <bits/stdc++.h>
using namespace std;
string a;
int n,b[200005],num;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
		for (int j=1;j<=b[i];j++)
		{
			cin>>a;
		}
		sum+=b[i];
	}
	
	int l=0,r=a.size();
	while (l>=r)
	{
		if (a[l]-'a'!=a[r]-'a')
		{
			num++;
		}
		l++;
		r--;
	}
	cout<<num;
	return 0;
}
