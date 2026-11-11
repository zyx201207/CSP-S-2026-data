#include <bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
   	    return 1;
   	else
   	    return 0;
    if(s1==s2)
        return 1;
    else
        return 0;
}
