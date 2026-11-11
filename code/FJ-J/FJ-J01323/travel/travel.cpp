#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(c2[0]-'0')*10+(c2[1]-'0');
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') a=0;
	else a=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') b=0;
	else b=1;
	if(a!=b){
		cout<<"1100";
		return 0;
	}
	if(a==1){
		cout<<"1111";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<"1111";
	else cout<<"1110";
	return 0;
}
