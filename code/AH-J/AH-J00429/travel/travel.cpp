#include <iostream>
#include <string>
#define int long long
using namespace std;
int sum1,sum2;
char a,b;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int len1=s1.size(),len2=s2.size();
	a=s1[len1-1],b=s2[len2-1];
	for(int i=0;i<len1-1;i++)
		sum1=sum1*10+(s1[i]-'0');
	for(int i=0;i<len2-1;i++)
		sum2=sum2*10+(s2[i]-'0');	
	if(c1==c2)
	{
		cout<<"1";
		if(sum1==sum2)
		{
			cout<<"1";
			if(a<='C'&&b<='C'||a>'C'&&b>'C')
			{
				cout<<"1";
				if(abs(a-b)==1)
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		}
			
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
