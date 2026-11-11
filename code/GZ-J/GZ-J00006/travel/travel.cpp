//GZ-J00006 观山湖中学 吴俊辰 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	ll a1,a2;
	if(s1[2]=='D'||s1[2]=='F')a1=0;
	else a1=1;
	if(s2[2]=='D'||s2[2]=='F')a2=0;
	else a2=1;
	if(a1!=a2){
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
