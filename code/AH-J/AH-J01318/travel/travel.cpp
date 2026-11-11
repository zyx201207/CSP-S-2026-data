#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c1,c2,ans;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans++;
		ll a1=0,a2=0;
		for(ll i=0;i<(ll)s1.size()-1;i++) a1=a1*10+s1[i]-'0';
		for(ll i=0;i<(ll)s2.size()-1;i++) a2=a2*10+s2[i]-'0';
		if(a1==a2){
			ans++;
			ll b1=0,b2=0;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') b1=1;
			else b1=2;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') b2=1;
			else b2=2;
			if(b1==b2){
				ans++;
				if(b1==2) ans++;
				else if(abs(s1[2]-'A'-(s2[2]-'A'))==1) ans++;
			}
		}
	}
	for(ll i=1;i<=ans;i++) cout<<1;
	for(ll i=ans+1;i<=4;i++) cout<<0;
	return 0;
} 
