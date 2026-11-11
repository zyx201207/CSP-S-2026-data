#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	string c1,s1,c2,s2;
	string ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+='1';
		string get1=s1.substr(0,2);
		string get2=s2.substr(0,2);
		if(get1==get2)
		{
			ans+='1';
			char side1=s1[2],side2=s2[2];
			if((side1<='C' and side2<='C') or ((side1=='D' and side2=='F') or (side1=='F' and side2=='D')))
			{
				ans+='1';
				if(((side1=='D' and side2=='F') or (side1=='F' and side2=='D')) or (side1+1==side2) or(side1-1==side2))
				{
					ans+='1';
				}
				else ans="1110";
			}
			else ans="1100";
		}
		else ans="1000";
	}
	else {
		ans="0000";
	}
	cout<<ans;
	return 0;
}
