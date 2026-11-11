#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	bool f=0;
    string s1,s2,c1,c2;
    cin>>s1>>s2>>c1>>c2;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=c1[i])
        {
            f=1;
        }
    }
    if(f)
    {
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(c2[0]==s2[0]&&c2[1]==s2[1])
    {
    	cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(c2[2]<='C'&&s2[2]<='C')
	{
		cout<<1;
	}
	else if(c2[2]>='D'&&s2[2]>='D')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(c2[2]+1==s2[2]||c2[2]-1==s2[2])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
