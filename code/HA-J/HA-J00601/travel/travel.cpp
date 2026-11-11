#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2) cout<<1;
	else {
		cout<<"0000"<<endl;
		return 0;
	}
	if (s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else {
		cout<<"000"<<endl;
		return 0;
	}
	num1=s1[2]-'A';
	num2=s2[2]-'A';
	if (num1<=2&&num2<=2) cout<<1;
	else if (num1>2&&num2>2) cout<<1;
	else {
		cout<<"00"<<endl;
		return 0;
	}
	if (abs(num1-num2)==1) cout<<1;
	else cout<<0;
	cout<<endl;
	return 0;
}
