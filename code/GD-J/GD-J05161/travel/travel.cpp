#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	string x;
	cin>>x;
	c1=(x[0]-'0')*10;
	c1+=x[1]-'0';
	cin>>x;
	s1=(x[0]-'0')*100+(x[1]-'0')*10+(x[2]-'A'+1);
	cin>>x;
	c2=(x[0]-'0')*10+(x[1]-'0');
	cin>>x;
	s2=(x[0]-'0')*100+(x[1]-'0')*10+(x[2]-'A'+1);
	if(c1==c2)
	{
		if((s1/10)==(s2/10))
		{
			if((s1%10<=3&&s2%10<=3)||(s1%10>=4&&s2%10>=4))
				cout<<"111";
			else
				cout<<"110";
		}
		else
			cout<<"100";
	}
	else
		cout<<"000";
	if((s1%10<=3&&s2%10<=3)||(s1%10>=4&&s2%10>=4))
	{
		if(abs(s1-s2)==1)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}
	else
		cout<<"0"<<endl;
	return 0;
}
