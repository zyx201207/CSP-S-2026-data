#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll n,m,a[N],cnt[N];
vector <int> num;
int x,flag;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			flag=0;
			for(int k=0;k<int(num.size());k++)
			{
				if(num[k]==a[j])
				{
					x=k;
					flag=1;
				}
			}
			if(flag==0)
			{
				num.push_back(a[j]);
			}
			else
			{
				for(int p=x;p<int(num.size());p++)
				{
					num.pop_back();
				}
			}
			//for(int l=0;l<int(num.size());l++)
			//{
			//	cout<<num[l]<<" ";
			//}
		//cout<<endl;
		}
		for(int j=0;j<int(num.size());j++)
		{
			cnt[num[j]]++;
		}
		num.clear();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
