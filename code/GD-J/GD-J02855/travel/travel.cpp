#include<bits/stdc++.h>
#define t long long
#define ll unsigned long long
using namespace std;
string c1,s1,c2,s2,ans;
int main(int argc,char** argv)
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F')s1[2]='E';
	if(s2[2]=='F')s2[2]='E';
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((s1[2]<=67)==(s2[2]<=67)){
				if(abs(s1[2]-s2[2])==1)ans="1111";
				else ans="1110";
			}
			else ans="1100";
		}
		else ans="1000";
	}
	else ans="0000";
	cout<<ans;
}
