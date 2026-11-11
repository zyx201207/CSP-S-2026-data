#include <bits/stdc++.h>
using namespace std;
	int a, b;
	bool f1=false, f2=false;
	string a1, b1;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b)
	cout<<1;
	else cout<<0;
	if(a1[0]==b1[0]&&a1[1]==b1[1]&&a1[2]!=b1[2]){
		cout<<1;
		f1=true;
	}
	else cout<<0;
	if(f1==true&&(int(a1[2])>=int('D')&&int(b1[2])>=int('D')||int(a1[2])<=int('C')&&int(b1[2])<=int('C'))){
		cout<<1;
		f2=true;
	}
	else cout<<0;
	if(f1==true&&f2==true&&(a1[2]=='D'&&b1[2]=='F'||a1[2]=='F'&&b1[2]=='D'||a1[2]=='A'&&b1[2]=='B'||a1[2]=='B'&&b1[2]=='A'||a1[2]=='B'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='B'))
		cout<<1;
	else cout<<0;
	return 0;
}
