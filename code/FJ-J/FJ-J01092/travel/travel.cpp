#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		int zuoweihao1=0;
		int zuoweihao2=0;
		for(int i=0;i<s1.size();i++)
		{
			if('0'<=s1[i]&&s1[i]<='9') zuoweihao1=zuoweihao1*10+(s1[i]-'0');
			else break;
		}
		for(int i=0;i<s2.size();i++)
		{
			if('0'<=s2[i]&&s2[i]<='9') zuoweihao2=zuoweihao2*10+(s2[i]-'0');
			else break;
		}
		if(zuoweihao1==zuoweihao2)
		{
			if((s1[s1.size()-1]=='C'&&s2[s2.size()-1]=='D')||(s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='C')) cout<<"1100";
			else{
				if((s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F')||(s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='D')) cout<<"1111";
				else if((s1[s1.size()-1]+1==s2[s2.size()-1])||(s1[s1.size()-1]==s2[s2.size()-1]+1)) cout<<"1111";
				else cout<<"1110";
			}
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;	
} 
