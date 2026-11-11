#include<iostream>
#include<cstring> 
#include<cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=0,f2=0,f3=0,f4=0;
	int s2_= (s2[0]-'0')*10+(s2[1]-'0'),s1_= (s1[0]-'0')*10+(s1[1]-'0');
	//cout<<s2_;
	int m=s1[2]-'A'+1,n=s2[2]-'A'+1;
	if(c1==c2)
	{
		f1=1;
		if(s1_==s2_)
		{
			f2=1;
			if((m<4&&n<4)||(m>3&&n>3))
			{
				f3=1;
				if(abs(m-n)==1||(abs(m-n)==2&&m>3&&n>3))
				{
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
// freopenÈ¥×¢ÊÍ
 
