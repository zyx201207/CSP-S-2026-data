#include<bits/stdc++.h>//正在接受暴力的洗礼 
using namespace std;
int n,m,a[200005],ans = 0;
int m__2()
{
	int max = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			if((a[j] & a[i]) > max)
			{
				max = a[j] & a[i];
				//cout<<a[j]<<' '<<a[i]<<' '<<max<<endl;
			}
		}
	}
	return max;
}
int m2(int m)
{
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	if(m == 2) ans = m__2();
	else
	{
		cout<<0;
		return 0;
	}
	cout<<ans;
}
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/
