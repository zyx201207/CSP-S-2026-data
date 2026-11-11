#include <bits/stdc++.h>
using namespace std;
vector<int> a[35];
int b[200005],c[200005],d[200005],e[200005];
void erjin(int x)
{
	int h = x,l=0;
	while (h !=0)
	{
		if (h%2==1)
		{
			a[l].push_back(x);	
		}
		h/=2;
		l++;
	}
}
int main()
{
	int x,m,z,r,ma;
	cin >> x >> m;
	for (int i = 1;i<= x;i++)
	{
		cin >> b[i];
		erjin(b[i]);
	}
	for (int i = 35;i>=0;i--)
	{
		if (a[i].size()>=m)
		{
			z = a[i].size();
			for (int j = 0;j<z;j++)
			{
				c[j] = a[i][j];
			}
			ma = i;
			break;
		}
	}
	sort (c+1,c+z+1);
	for (int i = ma-1;i>=0;i--)
	{
		if (a[i].size()>=m)
		{
			r = a[i].size();
			for (int j = 0;j<z;j++)
			{
				d[j] = a[i][j];
			}
			sort(d+1,d+r+1);
		}
		int cl = 0,dl =0,o=0,ans =0;
		for (int j = 1;j<= r+z;j++)
		{
			if (c[cl] >d[dl])
				dl++;
			else if(c[cl] == d[dl])
			{
				ans++;
				cl++;
				dl++;
				j++;
				e[o] = c[cl];
				o++;
			}
			else
				cl++;
		 } 
		 if (ans >=m)
		 {
		 	for (int j = 0;j<= ans;j++)
		 	{
		 		c[j] = e[j];
			 }
			 z = ans;
		 }
	}
	int qw = c[0],qd = c[1];
	int uy = qw&qd;
	cout << uy;

 } 
