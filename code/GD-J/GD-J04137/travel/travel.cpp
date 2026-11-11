#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a=1;
	if(a&&stoi(s1.substr(0,2))==stoi(s2.substr(0,2)))b=1;
	if(b&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))c=1;
	if(c&&(s1[2]+1==s2[2]||s2[2]+1==s1[2]+1))d=1;
	cout<<a<<b<<c<<d;
	return 0;
} 
