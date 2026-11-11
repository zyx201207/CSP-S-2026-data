#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int num=4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin >> c >> s >> cc >> ss;
	if(c==cc)
	{
		cout << "1";
		num--;
	    if(s[0]==ss[0] && s[1]==ss[1])
	    {
	    	cout << "1";
	    	num--;
	    	if((s[2]>='A' && s[2]<='C')&&(ss[2]>='A' && ss[2]<='C'))
	    	{
	    		cout << "1";
	    		num--;
	    		if(abs(s[2]-ss[2])==1)
				{
					cout << "1";
					num--;
				}
			}
			else if((s[2]=='D' && ss[2]=='F')||(s[2]=='F' && ss[2]=='D'))
	    	{
	    		cout << "11";
	    		num-=2;
			}
		}
	}
	while(num>0)
	{
		cout << "0";
		num--;
	}
	return 0;
} 
