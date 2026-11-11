#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int a,b;
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if(a==b)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C')cout<<1;
	else if('D'<=s1[2] && s1[2]<='F' && 'D'<=s1[2] && s1[2]<='F')cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(-1<=s1[2]-s2[2] && s1[2]-s2[2]<=1)cout<<1;
	else cout<<0;
}
