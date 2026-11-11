//GJ-J00285 中央民族大学附属中学贵阳学校 朱睿哲
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		if(b[1]==d[1])
	    {
	        cout<<"1";
	        if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))
	        {
		        cout<<"1";
		        if(b[2]+1==d[2]||b[2]-1==d[2])
		        {
		        	cout<<"1";
				}
				else
				{
					cout<<"0";
					return 0;
				}
	        }
        	else
	        {
	        	cout<<"00";
	        	return 0;
	        }
	    }
	    else
	    {
	        cout<<"000";
	        return 0;
	    }
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}
