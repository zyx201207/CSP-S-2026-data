#include<bits/stdc++.h>
using namespace std;
string a,s1,s2,s3,s4;
char s5,s6;
int t1,t2;
int n,m,i,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	s3=s1.substr(0,2);
	s4=s2.substr(0,2);
	s5=s1[2];
	s6=s2[2];
	if(s5=='D'||s5=='F') t1=2;
	else t1=1;
	if(s6=='D'||s6=='F') t2=2;
	else t2=1;
	if(s3!=s4){
		cout<<"1000";
		return 0;
	}
	if(t1!=t2){
		cout<<"1100";
		return 0;
	}
	if((s5=='A'&&s6=='C')||(s6=='A'&&s5=='C')) {
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
