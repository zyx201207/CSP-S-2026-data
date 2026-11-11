#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string aa,aaa,bb,bbb;
	cin>>aa>>aaa>>bb>>bbb; 
	int a[4]={};
	if(aa==bb)
	{
		a[0]=1;
		if(aaa[0]==bbb[0]&&aaa[1]==bbb[1])
		{
			a[1]=1;
			bool flag=((aaa[2]>='A'&&aaa[2]<='C'&&bbb[2]>='A'&&bbb[2]<='C')||(aaa[2]>='D'&&aaa[2]<='F'&&bbb[2]>='D'&&bbb[2]<='F'));
			if(flag)
			{
				a[2]=1;
				if(flag&&(aaa[2]=='A'&&bbb[2]=='B'||aaa[2]=='B'&&bbb[2]=='C')||(aaa[2]=='D'&&bbb[2]=='F'))
				{
					a[3]=1;
				}
				else
				{
					a[3]=0;
				}
			}
			else
			{
				a[2]=0;
			}
		}
		else
		{
			a[1]=0;
		}
	}
	else
	{
		a[0]=0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
