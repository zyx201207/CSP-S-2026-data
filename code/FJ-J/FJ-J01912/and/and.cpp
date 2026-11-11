#include<bits/stdc++.h>
using namespace std;
const int Max=2e5;
int n,m,a[Max+32],ans;
bool is[Max+32];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=29;i>=0;i--)
	{
		int tmp=(1<<i),num=0;
		for(int j=1;j<=n;j++)
		{
			if(is[j]==0&&(a[j]&tmp)!=0)num++;
		}
		if(num>=m)
		{
			ans+=tmp;
			for(int j=1;j<=n;j++)
				if((a[j]&tmp)==0)is[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
