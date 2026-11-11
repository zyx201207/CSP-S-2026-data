#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	ll a=(s1[0]-'0')*10+s1[1]-'0';
	ll b=(s2[0]-'0')*10+s2[1]-'0';
	if(a==b) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	ll f1=0,f2=0;
	if(s1[2]>='A'&& s1[2]<='C') f1=1;
	if(s2[2]>='A'&& s2[2]<='C') f2=1;
	if(f1==f2) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<1;
	else cout<<0;
	return 0;
} 
