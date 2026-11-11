#include<bits/stdc++.h>
using namespace std;;
typedef long long ll;
const int N = 1e4+7;
string c1,s1,c2,s2,ans;
int main(void)
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans+="1";
	else ans+="0";
	if(s1[0]==s2[0]&&s1[1]==s2[1])ans+="1";
	else ans+="0";
	if(ans[1]=='0')ans+="0";
	else 
	{
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))ans+="1";
		else ans+="0";
	}
	if(ans[2]=='0')ans+="0";
	else
	{
		if(abs(s1[2]-s2[2])==1)ans+="1";
		else ans+="0";
	}
	cout<<ans;
	return 0;
}
