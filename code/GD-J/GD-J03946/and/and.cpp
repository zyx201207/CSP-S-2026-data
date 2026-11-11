# include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s[1005],max=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		if (s[i-1] and s[i+1]>max)
		{
			max+=s[i-1] and s[i+1];
		}
	}
	cout<<max;
}
