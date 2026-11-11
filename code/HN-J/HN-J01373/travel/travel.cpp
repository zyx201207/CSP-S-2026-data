#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string l;
    getline(cin,l);
    if(l[0]==l[7]&&l[1]==l[8])
    {
        cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(l[3]==l[10]&&l[4]==l[11])
    {
        cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(abs(l[5]-l[12])<=2) 
    {
        if(l[5]=='A'||l[12]=='A')
        {
        	cout<<1;
        	if(l[5]=='C'||l[12]=='C')
            {
            	cout<<0;
            	return 0;
		    }
		    else
		    {
		    	cout<<1;
		    	return 0;
			}
		}
		else if(abs(l[5]-l[12])==1&&(l[5]=='B'||l[12]=='B'))
        {
        	cout<<"11";
        	return 0;
		}
		else if(l[5]=='C'||l[12]=='C')
        {
        	cout<<"00";
        	return 0;
		}
		else
		{
			cout<<"11";
			return 0;
		}
	}
	else
	{
		cout<<"00";
	}
    return 0;
}
