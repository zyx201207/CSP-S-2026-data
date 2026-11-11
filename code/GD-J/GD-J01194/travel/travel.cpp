#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const ll N=2e6+10,M=5e3+10;
string c1,s1,c2,s2;ll a1,a2;char b1,b2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	a1=(s1[0]-'0')*10+s1[1]-'0';
	a2=(s2[0]-'0')*10+s2[1]-'0';
	b1=s1[2];b2=s2[2];
	//cout<<a1<<" "<<a2<<"\n";
	if(a1==a2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}if((b1<='C'&&b2<='C')||(b1>='D'&&b2>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if(abs(b1-b2)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
