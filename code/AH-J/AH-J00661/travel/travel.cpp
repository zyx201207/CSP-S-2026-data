#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else 
	{
		cout<<"0000";
		return 0;
	}
	int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
	int x=s1[2]-'A'+1,y=s2[2]-'A'+1;
	if(a==b) 
	{
		cout<<"1";
		if((x-3<=0&&y-3<=0)||(x-3>0&&y-3>0))
		{
			cout<<"1";
			if(x-y==1||y-x==1)
				cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
	}
	else cout<<"000";
	return 0;
}
