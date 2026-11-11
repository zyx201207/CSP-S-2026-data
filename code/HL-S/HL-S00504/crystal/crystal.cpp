#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
long long n,m,res,ans = 1;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	int mo;
	mo = n / 2;
	mo+=1;
//	cout<<mo<<endl;
	for(int i = mo-1;i >= 1;i--)
	{
		m -= mo - a[i];
		if(m < 0)
		{
			break;
		}
		ans++;
//		cout<<m<<endl<<ans<<endl;
	}
	cout<<ans;
	return 0;
}