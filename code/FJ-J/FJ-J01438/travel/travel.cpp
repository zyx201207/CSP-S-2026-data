#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int car,carr;
	map<char,int> mp;
	mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=5,mp['F']=6;
	string a,b;
	cin>>car>>a;
	cin>>carr>>b;
	int flag=0;
	if(car!=carr)cout<<"0",flag=1;
	else cout<<"1";
	if(a[0]==b[0]&&a[1]==b[1]&&flag==0)cout<<"1";
	else cout<<"0",flag=1;
	if(((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C'))&&flag==0) cout<<"1";
	else cout<<"0",flag=1;
	if(abs(mp[a[2]]-mp[b[2]])<=1&&flag==0)cout<<"1";
	else cout<<"0";
	return 0;
}

