#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2; cin>>c1>>s1>>c2>>s2;
	bool m=c1==c2;
	if(m)cout<<"1";
	else cout<<"0";
	string a,b;
	a=s1.substr(0,2);
	b=s2.substr(0,2);
	bool s=a==b;
	if(s&&m)cout<<"1";
	else cout<<"0";
	char a1,b1;
	a1=s1[2];
	b1=s2[2];
	bool ture=(((a1>='D'&&a1<='F')&&(b1>='D'&&b1<='F'))||((a1>='A'&&a1<='C')&&(b1>='A'&&b1<='C')));
	if(ture&&m&&s) cout<<1;
	else cout<<0;
	if(ture&&(a1-1==b1||b1-1==a1)&&m&&s)cout<<1;
	else cout<<"0";
	return 0;
}
