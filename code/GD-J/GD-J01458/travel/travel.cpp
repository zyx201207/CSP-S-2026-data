#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(!(s2[0]==s4[0]&&s2[1]==s4[1]))
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int x=s2[2]-'A'+1,y=s4[2]-'A'+1;
	if(x>y)
	{
		swap(x,y);
	}
	if(x<=3&&y>=4)
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(x==1&&y==3)
	{
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
