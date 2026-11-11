#include<bits/stdc++.h>
using namespace std;
string s,s2,s3,s4,c,cc,cc2,c2;
int ans[10];
int a,b;
int abs(int a,int b)
{
	if(a>=b)
	{
		return a-b;
	}
	else
	{
		return b-a;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s2>>s3>>s4;
	if(s==s3)
	{
		ans[1]=1;
		c=s2[0]+s2[1];
		cc=s4[0]+s4[1];
		if((c==cc))
		{
			ans[2]=1;
			c=s2[2];
			cc=s4[2];
			if((((c=="A")||(c=="B")||(c=="C"))&&((cc=="A")||(cc=="B")||(cc=="C")))||(((c=="D")||(c=="F"))&&((cc=="D")||(cc=="F"))))
			{
				ans[3]=1;
				if(cc=="F")
				{
					cc=="E";
				}
				if(c=="F")
				{
					c=="E";
				}
				a=(c[0]-'0')-'0';
				b=(cc[0]-'0')-'0';
				if(abs(a,b)==1&&(!((c=="C")&&(cc=="D")))&&(!((cc=="C")&&(c=="D"))))
				{
					ans[4]=1;
				}
			}
			
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}
