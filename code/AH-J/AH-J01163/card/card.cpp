#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N = 5e5;
long long a[N];
long long ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	long long flag = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == a[i - 1])
		{
			ans[i] = ans[i - 1];
			flag++;
		}else{
			ans[i] = n + 1 - a[i] - flag;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
