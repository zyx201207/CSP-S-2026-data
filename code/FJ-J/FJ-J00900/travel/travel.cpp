#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FILE(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
bool inl(char c)
{return c=='A'||c=='B'||c=='C';}
bool inr(char c)
{return c=='D'||c=='F';}
int main(){
	FILE("travel")
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int c1,c2;
	string s,s1;
	cin>>c1>>s>>c2>>s1;
	map<char,int>mp;
	mp['A']=1;mp['B']=2;mp['C']=3;mp['D']=4;mp['F']=5;
	bool a=c1==c2,b=s[0]==s1[0]&&s[1]==s1[1];
	bool c=inl(s[2])&&inl(s1[2])||inr(s[2])&&inr(s1[2]);
	bool d=abs(mp[s[2]]-mp[s1[2]])==1;
	cout<<a<<(a&&b)<<(a&&b&&c)<<(a&&b&&c&&d);
}
