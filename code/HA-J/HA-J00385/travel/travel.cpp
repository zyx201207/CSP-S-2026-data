#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
string c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c+=s1[2];
	c+=s2[2];
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[1]==s2[1]&&(c=="AB"||c=="BA"||c=="AC"||c=="CA"||c=="BC"||c=="CB"||c=="DE"||c=="ED")) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[1]==s2[1]&&(c=="AB"||c=="BA"||c=="CB"||c=="BC"||c=="DE"||c=="ED")) cout<<1;
	else cout<<0;
	return 0;	
}
