#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
string ans="";
bool t1=false,t2=false,t3=false;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";t1=true;
	}
	else ans+="0";
	
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&t1){
		ans+="1";t2=true;
	}
	else ans+="0";
	
	if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))&&t1&&t2){
		ans+="1";t3=true;
	}
	else if((s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))&&t1&&t2){
		ans+="1";t3=true;
	}
	else if((s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))&&t1&&t2){
		ans+="1";t3=true;
	}
	else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s2[2]=='E')&&t1&&t2){
		ans+="1";t3=true;
	}
	else ans+="0";
	
	if(abs(s1[2]-s2[2])==1&&!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))&&t1&&t2&&t3)ans+="1";
	else ans+="0";
	
	cout<<ans<<"\n";
	return 0;
} 
