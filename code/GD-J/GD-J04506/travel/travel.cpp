#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,ans,sum;
	char s1,s2,s3,s4,s5,s6;
	cin>>c1>>s1>>s2>>s3>>c2>>s4>>s5>>s6;
	if((s3=='A')||(s3=='B')||(s3=='C'))
		ans=1;
	else
		ans=2;
	if((s6=='A')||(s6=='B')||(s6=='C'))
		sum=1;
	else
		sum=2;
	if(c1==c2)
		cout<<"1";
	else
		cout<<"0";
	if((c1==c2)&&((s1==s4)&&(s2==s5)))
		cout<<"1";
	else
		cout<<"0";

	if((c1==c2)&&((s1==s4)&&(s2==s5))&&(ans==sum))
	{
		cout<<"1";							
	}
	else
		cout<<"0";
	if((c1==c2)&&((s1==s4)&&(s2==s5))&&(ans==sum))
	{
		if(((s3=='A')&&(s6=='B'))||((s3=='B')&&(s6=='C'))||((s3=='D')&&(s6=='F')))
			cout<<"1";
		else
			cout<<"0";							
	}
	else
		cout<<"0";
	return 0;
}

