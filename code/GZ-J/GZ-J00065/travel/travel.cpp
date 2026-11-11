//GZ-J00065遵义第四中学李子煜
#include <bits/stdc++.h>
using namespace std;
char a[10] = {'A','B','C','D','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	string c2,c4;
	cin >> c1 >> c2 >> c3 >> c4;
	int t1,t2,t3,t4;
	if (c1 == c3)
	{
		t1 = 1;
	}
	else
	{
		t1 = 0;
	}
	if (c2[0] == c4[0] && c2[1] == c4[1] && t1 != 0)
	{
		t2 = 1;
	}
	else
	{
		t2 = 0;
	}
	if (c2[2] == a[0] && t2 != 0)
	{
		if (c4[2] == a[1])
		{
			t3 = 1;
			t4 = 1;
		}
		else if (c4[2] == a[2])
		{
			t3 = 1;
			t4 = 0;
		}
		else
		{
			t3 = 0;
			t4 = 0;
		}
	}
	if (c2[2] == a[1]  && t2 != 0)
	{
		if (c4[2] == a[0] || c4[2] == a[2])
		{
			t3 = 1;
			t4 = 1;
		}
		else
		{
			t3 = 0;
			t4 = 0;
		}
	}
	if (c2[2] == a[2]  && t2 != 0)
	{
		if (c4[2] == a[1])
		{
			t3 = 1;
			t4 = 1;
		}
		else if (c4[2] == a[0])
		{
			t3 = 1;
			t4 = 0;
		}
		else
		{
			t3 = 0;
			t4 = 0;
		}
	}
	if (c2[2] == a[3]  && t2 != 0)
	{
		if (c4[2] == a[4])
		{
			t3 = 1;
			t4 = 1;
		}
		else
		{
			t3 = 0;
			t4 = 0;
		}
	}
	if (c2[2] == a[4]  && t2 != 0)
	{
		if (c4[2] == a[3])
		{
			t3 = 1;
			t4 = 1;
		}
		else
		{
			t3 = 0;
			t4 = 0;
		}
	}
	else 
	{
		t3 = 0;
		t4 = 0;
	}
	cout << t1 << t2 << t3 << t4;
	return 0;
}
