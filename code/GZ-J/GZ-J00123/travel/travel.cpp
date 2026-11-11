//GZ-J00123 »ÆºÆÈ» 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void fx(){
	string s1 ,c1 ,s2 ,c2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	ll l1 ,l2;l1=l2=0;
	map<char,ll>mp;
    mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	if(c1==c2)ans+="1" ,l1=1;
	else ans+="0";
	if(l1 && s1[0]==s2[0] && s1[1]==s2[1])ans+="1",l2=1;
	else ans+="0";
	if(l1 && l2 && mp[s1[2]]==mp[s2[2]])ans+="1";
	else ans+="0";
	char a ,b;
	a=max(s1[2],s2[2]); b=min(s1[2],s2[2]); 
	if(a-b==1 && a!='D' && l1 && l2)ans+="1";
	else ans+="0";
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll t=1;
	while(t--)fx();
}
