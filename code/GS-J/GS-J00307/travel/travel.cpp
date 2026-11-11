#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(s1=="A"&&s2=="B") cout<<"1";
	else cout<<"0";
	if(s1=="B"&&s2=="C") cout<<"1";
	else cout<<"0";
	if(s1=="D"&&s2=="F") cout<<"1";
	else cout<<"0";
	return 0;
}
