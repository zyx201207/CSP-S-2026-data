#include<bits/stdc++.h>
using namespace std;
const string follow="ABC DF";
map<char,bool> mp={{'A',1},{'B',1},{'C',1},{'D',0},{'F',0}};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	string ans="";
	ans+=to_string(int(a1==b1));
	int a=(a2[0]-'0')*10+a2[1]-'0';
	int b=(b2[0]-'0')*10+b2[1]-'0';
	ans+=to_string(int((a==b)&(a1==b1)));
	ans+=to_string(int((!(mp[a2[2]]^mp[b2[2]]))&(a==b)&(a1==b1)));
	string need_find="";
	need_find+=a2[2];
	need_find+=b2[2];
	ans+=to_string(int(follow.find(need_find)!=string::npos));
	cout<<ans;
}
