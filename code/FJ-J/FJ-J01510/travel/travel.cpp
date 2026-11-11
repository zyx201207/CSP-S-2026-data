#include<bits/stdc++.h>
using namespace std;
int a[6]={'0','A','B','C','D','F'};
int main()
{
	freopen("travel.in","r",in)
	freopen("travel.our","w",our)
	int c1,c2,n=0,m=0,k=0,w=0,p=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	w=(s1[0]-'0')+(s1[1]-'0');
	p=(s2[0]-'0')+(s2[1]-'0');

	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1!=c2)
	{
		cout<<"0";
	}
	else
	{
		if(w==p)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	if(c1!=c2)
	{
		cout<<"0";
	}
	else
	{
		if(w!=p)
		{
			cout<<"0";
		}
		else
		{
			if(s1[2]==a[1] || s1[2]==a[2] || s1[2]==a[3])
			{
				if(s2[2]==a[1] || s2[2]==a[2] || s2[2]==a[3])
				{
					cout<<"1";
					n=1;
				}
				if(s2[2]==a[4] || s2[2]==a[5])
				{
					cout<<"0";
					n=0;
				}
			}
			if(s1[2]==a[4] || s1[2]==a[5])
			{
				if(s2[2]==a[4] || s2[2]==a[5])
				{
					cout<<"1";
					n=1;
				}
				if(s2[2]==a[1] || s2[2]==a[2] || s2[2]==a[3])
				{
					cout<<"0";
					n=0;
				}
			}
		}
	}
	if(c1!=c2)
	{
		cout<<"0";
	}
	else
	{
		if(w!=p)
		{
			cout<<"0";
		}
		else
		{
			if(n=0)
			{
				cout<<"0";
			}
			else
			{
				for(int i=1;i<=5;i++)
				{
					if(s1[2]==a[i])
					{
						k=i;
					}
					if(s2[2]==a[i])
					{
						m=i;
					}
				}
				if((k==3 && m==4) || (k==4 && m==3)) 
				{
					cout<<"0";
				}
				else
				{
					if(k+1==m || k-1==m)
					{
					cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
			}
		}
	}
	return 0;
	
}