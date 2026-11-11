#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long int n,m;
	cin >> n >> m;
	int a[500005] = {0}; //all cards' order	
	int ans[300005] = {0}; //number-i remaining times
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		int top = 0;
		bool c[300005] = {0}; //cards' appearence
		int d[300005] = {0}; //cards on desktop
		//cout << "it has been reseted" << endl;//
		for(int j = 1;j<=n-i+1;j++)
		{
			if(c[a[j+i-1]])
			{
				//cout << a[j+1-1] << "has appeared as" << c[a[j+i-1]]<< endl; //
				int topp = top;
				for(int k = topp;k >= 1;k--)
				{
					if(d[k] != a[j+i-1])
					{
						c[d[k]] = 0;
						d[k] = 0;
						top --;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				c[a[j+i-1]] = 1;
				//cout << a[j+i-1] << "is appearing";//
				top ++;
				d[top] = a[j+i-1];
			}
		}
		for(int j = 1;j <= top;j++)
		{
			ans[d[j]] ++;
		}
		//for(int mm = 1;mm <= top;mm++)//
		//{//
		//	cout << d[mm] << " ";//
		//}//
		//cout << endl;//
	}
	for(int i = 1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
