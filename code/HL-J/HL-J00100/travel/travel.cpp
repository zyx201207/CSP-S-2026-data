#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	int ans=0;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2)ans+=1000;

    if(ans==1000){
    	if(s1[0]==s2[0]&&s1[1]==s2[1]) ans+=100;
	}

	if(ans==1100)
    	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'&&s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D')ans+=10;

	if(ans==1110)
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'&&s1[2]=='F'&&s2[2]=='D')ans+=1;

	if(ans==0)cout<<"0000";
	if(ans!=0)cout<<ans;
    return 0;
}//if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'&&s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F')cout<<"1";else cout<<"0";
//test 1: 01 01A 02 01A
//h13 AB AC BC DF     ->    BA CA CB FD
//h15 AB BC CD DF     ->    BA CB DC FD
//if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'&&s1[2]=='F'&&s2[2]=='D')cout<<"1";else cout<<'0';
