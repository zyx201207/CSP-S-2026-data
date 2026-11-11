#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
        	cout<<1;
        	if(s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'&&s1[2]<='E'&&s2[2]<='E')
        	{
        		cout<<1;
        		if(s1[2]+1==s2[2]&&s1[2]+1<68&&s1[2]+1<70||s1[2]+1==s2[2]&&s1[2]+1>64&&s1[2]+1>67||s1[2]-1==s2[2]&&s1[2]-1>64&&s1[2]+1<68||s1[2]-1==s2[2]&&s1[2]+1<70&&s1[2]-1>67)
        		{
        			cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
	    }
	    else
	    {
    		cout<<"000";
    	}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
