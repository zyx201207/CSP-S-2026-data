#include<bits/stdc++.h>
using namespace std;
string c1_kqx,s1_kqx,c2_kqx,s2_kqx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//cin
	cin>>c1_kqx>>s1_kqx>>c2_kqx>>s2_kqx;
	bool f1_kqx;
	//[1]
	if (c1_kqx[0]==c2_kqx[0] && c1_kqx[1]==c2_kqx[1])
	{
		f1_kqx=true;
	}
	else
	{
		f1_kqx=false;
	}
	cout<<f1_kqx;
	bool f2_kqx;
	//[2]
	if (f1_kqx && s1_kqx[0]==s2_kqx[0] && s1_kqx[1]==s2_kqx[1])
	{
		f2_kqx=true;
	}
	else
	{
		f2_kqx=false;
	}
	cout<<f2_kqx;
	bool f3_kqx;
	//[3]
	if (f2_kqx)
	{
		if (s1_kqx[2]<='C')
		{
			if (s2_kqx[2]<='C')
			{
				f3_kqx=true;
			}
			else
			{
				f3_kqx=false;
			}
		}
		else
		{
			if (s2_kqx[2]>='D')
			{
				f3_kqx=true;
			}
			else
			{
				f3_kqx=false;
			}
		}
	}
	else
	{
		f3_kqx=false;
	}
	cout<<f3_kqx;
	bool f4_kqx;
	//[4]
	if (f3_kqx)
	{
		if ((int(s1_kqx[2]) + 1 == int(s2_kqx[2])) || 
		(int(s2_kqx[2]) + 1 == int(s1_kqx[2])))
		{
			f4_kqx=true;
		}
		else
		{
			f4_kqx=false;
		}
	}
	else
	{
		f4_kqx=false;
	}
	cout<<f4_kqx;
	//remember to delete "//"of"//freopen(----)"
	return 0;
}
