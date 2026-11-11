#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","stdin","r");
	freopen("card.out","stdout","w");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<n<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}
