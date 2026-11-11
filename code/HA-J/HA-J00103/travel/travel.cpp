#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string s1,s2,s3,s4;
ll f1=0;
ll f2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	ll t1=stoi(s1);
	ll t3=stoi(s3);
	if(t1==t3){
		string s5,s6;
		s5+=s2[0]+s2[1];
		s6+=s4[0]+s4[1];
		//ll tmp1=stoi(s5);
		//ll tmp2=stoi(s6);
		if(s5==s6){
			if(s2[2]=='F'||s2[2]=='D') f1=1;
			if(s4[2]=='F'||s4[2]=='D') f2=1;
			if(f1==f2){
				t1=s2[2]-'a';
				t3=s4[2]-'a';
				if((t1+t3)%2==0||s2[2]=='C'&&s4[2]=='D'||s2[2]=='D'&&s4[2]=='C') cout<<"1110";
				else cout<<"1111";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
