#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll c1,c2,fl=1;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<0;
		fl=0;
	}
	ll flag=1,flag1=1;
	for(ll i=0;i<2;i++){
		if(s1[i]!=s2[i])flag=0;
	}
	if(flag&&fl)cout<<1;
	else cout<<0;
	if(flag==1&&s1[2]>'C'&&s2[2]>'C'&&fl){
		cout<<1;
	}
	else if(flag==1&&s1[2]<'D'&&s2[2]<'D'&&fl){
		cout<<1;
	}
	else {
		cout<<0;
		flag1=0;
	}
	ll fl2=1;
	if(max(s1[2],s2[2])-min(s1[2],s2[2])>1)fl2=0;
	else if(max(s1[2],s2[2])=='D')fl2=0;
	if(fl&&flag&&flag1&&fl2)cout<<1;
	else cout<<0;
	return 0;
} 
