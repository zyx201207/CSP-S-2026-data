#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	string r1=s1.substr(0,2),r2=s2.substr(0,2);
	s1.erase(0,2);
	s2.erase(0,2);
	if(r1!=r2){
		cout<<"000";
		return 0;
	}
	else cout<<1;
	ll f=0;
	if(s1[0]>='A'&&s1[0]<='C'&&s2[0]>='A'&&s2[0]<='C'){
		cout<<1;
		f=1;
	}else if(s1=="D"&&s2=="F"){
		cout<<1;
		f=2;
	}else if(s1=="F"&&s2=="D"){
		cout<<1;
		f=2;
	}
	else cout<<0;
	if(f==1&&abs(s1[0]-s2[0])!=1) f=0;
	else if(f==2) f=1;
	if(f&&r1==r2) cout<<1;
	else cout<<0;
	return 0;
}
