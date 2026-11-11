#include<bits/stdc++.h>//´íµÃÀëÆ×£¬ÎÞ½â 
using namespace std;
int a[500005],top,flg,s[300005],b[500005],m,x;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		top = 1;
		for(int j = i+1;j <= n;j++)
		{
			b[top] = a[top];
			top++;
			if(b[top] == a[i])
			{ 
				for(int k = i;k < j;k++)
				{
					top--;
					flg++;
				}
			}
		}
		for(int j = 1;j <= top;j++)
		{
			s[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout<<s[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
