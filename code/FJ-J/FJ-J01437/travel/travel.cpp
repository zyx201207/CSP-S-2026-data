#include<bits/stdc++.h>
#define int long long
using namespace std;
map<char,int> mp;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	mp['A']=1,mp['B']=2,mp['C']=3;
	mp['D']=5,mp['F']=6;
	int n,m;
	string s,t;
	cin>>n>>s>>m>>t;
	char sit1=s[s.size()-1],sit2=t[t.size()-1];
	s.erase(s.size()-1);
	t.erase(t.size()-1);
	if(n==m){
		cout<<"1";
	}
	else cout<<"0";
	if(s==t&&n==m){
		cout<<"1"; 
	}
	else cout<<"0";
	if(s==t&&n==m&&((mp[sit1]<4&&mp[sit2]<4)||(mp[sit1]>4&&mp[sit2]>4))){
		cout<<"1";
	}
	else cout<<"0";
	if(s==t&&n==m&&abs(mp[sit1]-mp[sit2])==1){
		cout<<"1";
	}
	else cout<<"0";
 } 
