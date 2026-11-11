#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
bool tc(char x,char y){
	if((ll(x)<=ll('C')&&ll(y)<=ll('C'))||(ll(x)>=ll('D')&&ll(y)>=ll('D'))) return 1;
	return 0;
}
bool xl(char x,char y){
	ll dis=ll(x)-ll(y);
	if(dis<=1) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f1=1;
	else f1=0;
	ll rs=ll(s1[0]-'0')*10+ll(s1[1]-'0');
	ll xs=ll(s2[0]-'0')*10+ll(s2[1]-'0');
	if(f1&&rs==xs) f2=1;
	else f2=0;
	if(f1&&f2&&tc(s1[2],s2[2])) f3=1;
	else f3=0;
	if(f1&&f2&&f3&&xl(s1[2],s2[2])) f4=1;
	else f4=0;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
