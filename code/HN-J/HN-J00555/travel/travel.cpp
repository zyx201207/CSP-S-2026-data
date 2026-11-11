#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int sum1=s1[0]-'0'*10+s1[1]-'0';
	int sum2=s2[0]-'0'*10+s2[1]-'0';
	if(sum1==sum2&&c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(sum1==sum2&&(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')&&c1==c2){
		cout<<1;
	}
	else if(c1==c2&&sum1==sum2&&(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='A')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int g=s1[2]-'0';
	int h=s2[2]-'0';
	if(c1==c2&&sum1==sum2&&(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')){
		cout<<1;
	}
	else if(c1==c2&&sum1==sum2&&(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C')){
		cout<<0;
	}
	else if(c1==c2&&sum1==sum2&&abs(g-h)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
