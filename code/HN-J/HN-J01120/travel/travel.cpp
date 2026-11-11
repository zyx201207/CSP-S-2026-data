#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
unordered_map<char,int> mp={
	{'A',1},
	{'B',2},
	{'C',3},
	{'D',4},
	{'F',5}
};
/*
rp++



*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=(c1==c2);
	int b=a&&(s1.substr(0,2)==s2.substr(0,2));
	int c=b&&((mp[s1[2]]<=3&&mp[s2[2]]<=3)||(mp[s1[2]]>3&&mp[s2[2]]>3));
	int d=c&&(abs(mp[s1[2]]-mp[s2[2]])==1);
	cout<<a<<b<<c<<d;
	return 0;
}

