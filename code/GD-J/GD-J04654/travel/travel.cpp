#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string c1,s1,c2,s2;
map<char,int> mp,mp1;
void chk(string c1,string s1,string c2,string s2)
{
	if(c1!=c2)
	{
		cout<<"0000";
		return ;
	}
	cout<<"1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"000";
		return ;
	}
	cout<<"1";
	if(mp[s1[2]]!=mp[s2[2]])
	{
		cout<<"00";
		return ;
	}
	cout<<"1";
	if(abs(mp1[s1[2]]-mp1[s2[2]])!=1)
	{
//		cout<<s1[2]<<" "<<s2[2]<<" ";
		cout<<"0";
		return;
	}
	cout<<"1";
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	mp1['A']=1,mp1['B']=2,mp1['C']=3;
	mp1['D']=5,mp1['F']=6;
	chk(c1,s1,c2,s2);
	
	return 0;
}
