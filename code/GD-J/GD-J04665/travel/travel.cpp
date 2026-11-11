#include<bits/stdc++.h>
#define ll long long
//unsigned long long
//priority_queue<int,vector<int>,greater<int>>;
using namespace std;
string c1,c2,s1,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans+='1';
	else ans+='0';
	if(ans=="1"&&s1[0]==s2[0]&&s1[1]==s2[1])ans+='1';
	else ans+='0';
	if(ans=="11"&&(((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))||((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))))ans+='1';
	else ans+='0';
	if(ans=="111"&&abs(s1[2]-s2[2])==1)ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}

