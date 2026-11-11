#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2,s3,s4;
	char c1,c2;
	cin>>s1>>s2>>c1>>s3>>s4>>c2;
	if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s2!=s4)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	int s5,s6;
	s5=c1-'A'+1;
	s6=c2-'A'+1;
	if(!((s5>=4&&s6>=4)||(s5<=3&&s6<=3)))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(!((s5<=3)&&(abs(s5-s6)==1))||((s5>=4)&&(abs(s5-s6)==2)))
	{
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}
