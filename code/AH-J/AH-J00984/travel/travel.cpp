#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
bool check1(string s1,string s2)
{
	bool b1=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'),b2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	if(b1==b2)
		return 1;
	else
		return 0;
}
bool check2(string s1,string s2)
{
	if(abs(mp[s1[2]]-mp[s2[2]])==1)
		return 1;
	else
		return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=5,mp['F']=6;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(check1(s1,s2)) 
			{
				cout<<1;
				if(check2(s1,s2))
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
