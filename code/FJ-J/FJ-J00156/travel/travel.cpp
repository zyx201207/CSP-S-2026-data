#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int  main()
{
	int pd=0;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
	{
	    cout<<"1 ";
	    if(c1[1]==c2[1]&&c1[2]==c2[2])
	    {
	    	cout<<"1 ";
	    	if(s1[3]=>"A"&&s2[3]=<"C"&&s1[3]!=s2[3])
			{
				pd+=1;
			}
			else if(s1[3]=>"C"&&s2[3]=<"D")
			{
			    pd++;
			    if(pd==2)
			    {
			    	cout<<"1 ";
				}
			} 
			else cout<<"0 0";
		}
		else cout<<"0 0 0";
	}
    else cout<<"0 0 0 0";
    return 0;
}
