#include<bits/stdc++.h>
using namespace std;
int x,y,k,b,ss1,ss3;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ss1>>s2>>ss3>>s4;
	if(ss1==ss3)
	{
		if(int(s2[0])*10+int(s2[1])==int(s4[0])*10+int(s4[1]))
		{
			int flag=0;
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
			{
				if(s4[2]=='A' || s4[2]=='B' || s4[2]=='C')
				{
					flag=1;
				}
			}
			else if(s4[2]=='D' && s4[2]=='F')
			{
				flag=0;
			}
			if(flag==1)
			{
				if(abs(int(s2[2])-int(s4[2]))==1)
				{
					cout<<"1111";
				}
				else
					cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<1000;
	}
	else {cout<<"0000";
}
	
	return 0;
}
