#include<bits/stdc++.h>
//#include<string>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string a,b,a1,b1;
	a='0';
	b='0';
	a1='0';
	b1='0';
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a='1';
//		if(s1/10==s2/10)
//		{
//			b='1';
//			if((s1%10==C&&s2%10==D)||(s1/10==D&&s2/10==C))
//			{
//				a1='0';
//			}
//			else{
//				a1='1';
//				if(s1%10+1==s2%10||s1%10==s2%10+1)
//				{
//					b1='1';
//				}
//			}
//		}
	}
	cout<<a<<b<<a1<<b1;
	
	return 0;
}
