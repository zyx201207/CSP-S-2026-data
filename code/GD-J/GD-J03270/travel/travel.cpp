#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,st1,st2;
int n,len;
bool check1()
{
	for(int i=1;i<=2;i++)
	{
		if(s1[i]!=st1[i]) return 0;
	}
	return 1;
}
bool check2()
{
	if(!check1()) return 0;
	for(int i=1;i<=2;i++)
	{
		if(s2[i]!=st2[i]) return 0;
	}
	return 1;
}
bool check3()
{
	if(!check2()) return 0;
	if(s2[3]-'A'>2&&st2[3]>2) return 1;
	if(s2[3]-'A'<3&&st2[3]-'A'<3) return 1;
	return 0;
}
bool check4()
{
	if(!check3()) return 0;
	if(s2[3]-'A'>2&&st2[3]>2) return 1;
	if(s2[3]-'A'<3&&st2[3]-'A'<3)
	{
		if(abs((s2[3]-'A')-(st2[3]-'A'))==1) return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>st1>>st2;
	s1=" "+s1,s2=" "+s2,st1=" "+st1,st2=" "+st2;
	cout<<check1()<<check2()<<check3()<<check4();
	return 0;
}

