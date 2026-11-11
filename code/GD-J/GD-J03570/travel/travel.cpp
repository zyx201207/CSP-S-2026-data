#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
string s1,s2,s3,s4;
int b[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	b['A']=1;b['B']=1;b['C']=1;b['D']=2;b['F']=2;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s2[0]!=s4[0]||s2[1]!=s4[1]){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	if(b[s2[2]]!=b[s4[2]]){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')||(s2[2]=='C'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='A'))cout<<"1";
	else cout<<"0";
	return 0;
} 
