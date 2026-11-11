#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
long long a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(s1[0]-'0')*10+(s1[1]-'0');
	c=(c2[0]-'0')*10+(c2[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b==d){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b==d&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&b==d&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
