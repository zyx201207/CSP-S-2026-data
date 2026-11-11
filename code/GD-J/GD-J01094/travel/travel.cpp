#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	char a,b,c;
	cin>>a>>b>>c;
	string s1_1;
	s1_1=s1_1+a+b;
	char s1_2=c;
	cin>>c2;
	cin>>a>>b>>c;
	string s2_1;
	s2_1=s2_1+a+b;
	char s2_2=c;
	char ans1,ans2,ans3,ans4;
	if(c1==c2) ans1='1';
	else ans1='0';
	if((s1_1==s2_1)&&(ans1=='1')) ans2='1';
	else ans2='0';
	if((ans2=='1')&&((s1_2=='A'&&s2_2=='B')||(s1_2=='B'&&s2_2=='A')||(s1_2=='C'&&s2_2=='B')||(s1_2=='B'&&s2_2=='C')||(s1_2=='C'&&s2_2=='A')||(s1_2=='A'&&s2_2=='C')||(s1_2=='D'&&s2_2=='F')||(s1_2=='F'&&s2_2=='D'))) ans3='1';
	else ans3='0';
	if((ans3=='1')&&((s1_2=='A'&&s2_2=='B')||(s1_2=='B'&&s2_2=='A')||(s1_2=='C'&&s2_2=='B')||(s1_2=='B'&&s2_2=='C')||(s1_2=='D'&&s2_2=='F')||(s1_2=='F'&&s2_2=='D'))) ans4='1';
	else ans4='0';
	string ans;
	ans=ans+ans1+ans2+ans3+ans4;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
