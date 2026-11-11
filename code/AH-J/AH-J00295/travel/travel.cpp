#include<bits/stdc++.h>
using namespace std;
//nobody should be undefined
string c1,s1,c2,s2,t1,t2;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    t1=s1[0]+s1[1];
    t2=s2[0]+s2[1];
    if(c1!=c2)
    {
		cout<<"0000";
	}
	else if(t1!=t2)
	{
		cout<<"1000";
	}
	else if((!('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'))&&(!('D'<=s1[2]&&s1[2]<='E'&&'D'<=s2[2]&&s2[2]<='E')))
	{
		cout<<"1100";
	}
	else if(!(abs(s1[2]-s2[2])==1))
	{
		cout<<"1110";
	}
	else
	{
		cout<<"1111";
	}
}
