#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,c,a,b;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>a>>b;
	if((s[2]=='C'&&b[2]=='D')||(s[2]=='D'||b[2]=='C'))
	{
		f=1;
	}
	if(c==a){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==b[0]&&s[1]==b[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(abs(int(s[2]-b[2])<=2)&&f==0)
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(int(s[2]-b[2])<=1)&&f==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
