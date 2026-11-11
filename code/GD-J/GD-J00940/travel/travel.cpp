#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("travel.in",'r',stdin);
	freopen ("travel.out",'w',stdin);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[4]={0};
	bool t1=false,t2=false;
	if (c1[0]==c2[0] && c1[1]==c2[1])
	{
		a[0]=1;
		if (s1[0]==s2[0] && s1[1]==s2[1])
		{
			a[1]=1;
			for (char i='A';i<='C';i++)
			{
				if (s1[2]==i)
				{
					t1=true;
				}
				if (s2[2]==i)
				{
					t2=true;
				}
			}
			if (t1 && t2)
			{
				a[2]=1;
				if (s1[2]=='B' || s2[2]=='B')
				{
					a[3]=1;
				}
			}
			else if (!t1 && !t2)
			{
				a[2]=1;
				a[3]=1;
			}
		}
	}
	for (int i=0;i<4;i++)
	{
		cout<<a[i];
	}
	return 0;
	fclose (stdout);
	fclose (stdout);
}
