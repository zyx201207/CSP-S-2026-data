#include <bits/stdc++.h>
using namespace std;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	F;
	int a,b;
	string s,t;
	map<char,int> mp;
	mp['A']=11;
	mp['B']=12;
	mp['C']=13;
	mp['D']=25;
	mp['F']=26;
	cin>>a>>s>>b>>t;
	int ans=1;
	ans&=(a==b);
	cout<<ans;
	ans&=(s.substr(0,2)==t.substr(0,2));
	cout<<ans;
	ans&=(mp[s[2]]/10==mp[t[2]]/10);
	cout<<ans;
	ans&=(abs(mp[s[2]]-mp[t[2]])==1);
	cout<<ans;
	return 0;
}
