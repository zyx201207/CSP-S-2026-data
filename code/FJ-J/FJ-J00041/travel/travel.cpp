#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> c2 >> s1 >> s2;
	int n,m;
	if(c1[0] == '0')
	{
		n = int(c1[1]-'0');
	}
	else
	{
		n = int(c1[0]-'0')*10 + int(c1[1]-'0');
	}
	if(s1[0] == '0')
	{
		m = int(s1[1]-'0');
	}
	else
	{
		m = int(s1[0]-'0')*10 + int(s1[1]-'0');
	} 
    if(n != m)
    {
    	cout << "0000";
    	return 0;
    }
    for(int i = 0;i<c2.size();i++)
    {
    	if(c2[i]>= '0' && c2[i] <='9')
    	{
    		if(c2[i] != s2[i])
    		{
    			cout << "1000";
    			return 0;	
    		}
    	}
    	else
    	{
    		int k = int(c2[i]-'A');
    		int d = int(s2[i]-'A');
    		if(abs(k-d) == 1)
    		{
    			if(k+d == 5)
    			{
    				cout << "1100";
    				return 0;
    			}
    			else
    			{
    				cout << "1111";
    				return 0;
    			}
    		}
    		else
    		{
    			if(k+d == 2)
    			{
    				cout << "1110";
    				return 0;
    			}
    			else
    			{
    				cout << "1100";
    				return 0;
    			}
    		}
    	}
    }
    return 0;
}
