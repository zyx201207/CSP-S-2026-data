#include<bits/stdc++.h>

using namespace std;
struct SEAT{
	bool lr;//0ио1об
	int lie;
	int hang;
	int chex; 
	
};
SEAT seata,seatb;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	
	cin>>s1>>s2>>s3>>s4;
	int t=0;
	for(int i=0;i<s1.size();i++)
	{
		t=t*10+s1[i]-'0';
	}
	seata.chex=t;
	t=0;
	for(int i=0;i<s2.size()-1;i++)
	{
		t=t*10+s2[i]-'0';
	}
	seata.lie=t;
	if(s2[s2.size()-1]=='D'||s2[s2.size()-1]=='F') seata.lr=0;
	else seata.lr=1;
	
	seata.hang=int(s2[s2.size()-1]-64);
	if(seata.hang==6) seata.hang--;
	
	t=0;
	for(int i=0;i<s3.size();i++)
	{
		t=t*10+s3[i]-'0';
	}
	seatb.chex=t;
	t=0;
	for(int i=0;i<s4.size()-1;i++)
	{
		t=t*10+s4[i]-'0';
	}
	seatb.lie=t;
	if(s4[s4.size()-1]=='D'||s4[s4.size()-1]=='F') seatb.lr=0;
	else seatb.lr=1;
	seatb.hang=int(s4[s4.size()-1]-64);
	if(seatb.hang==6) seatb.hang--;
	
	
	string ans;
	if(seata.chex==seatb.chex)
	{
		ans+="1";
		if(seata.lie==seatb.lie)
		{
			ans+="1";
			if(seata.lr==seatb.lr)
			{
				ans+="1";
				if(abs(seata.hang-seatb.hang)==1) ans+="1";
				else ans+="0";
			}
			else
			{
				ans+="0";
			}
		}
		else
		{
			ans+="0";
		}
	}
	else
	{
		ans+="0";
	}
	
	while(ans.size()<4)
	{
		ans+="0";
	}
	cout<<ans;
	
	return 0;
 } 
