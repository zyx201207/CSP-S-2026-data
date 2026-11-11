#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int l1,l2;
long long zh(string a)
{
	long long len=a.size(),num=0;
	for (int i=len-1;i>=0;i--)
	{
		num=num*10+(a[i]-'0');
	}
	return num;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if (zh(s1)==zh(s3))
	{
		cout<<1;
		if (s2[0]==s4[0] && s2[1]==s4[1])
		{
			cout<<1;
			l1=s2[2]-'A'+1;
			l2=s4[2]-'A'+1;
			if ((l1<=3 && l2<=3) || (l1>=4 && l2>=4))
			{
				cout<<1;
				if (abs(l1-l2)==1)
				{
					cout<<1;
				}else
				{
					cout<<0;
				}
			}else
			{
				cout<<"00";
			}
		}else
		{
			cout<<"000";
		}
	}else
	{
		cout<<"0000";
	}
}
