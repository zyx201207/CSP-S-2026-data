#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("trave11.in","r",stdin);
	freopen("trave1.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==c2)cout<<"1";
	else cout<<"0";
	if(c1==c2)
		if(s1-"A"==s2-"A")cout<<"1";
		else cout<<"0";
	return 0;
}
