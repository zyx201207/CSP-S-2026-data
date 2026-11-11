#include<bits/stdc++.h>
using namespace std;
string c_1,c_2,s_1,s_2;
bool f_1,f_2,f_3,f_4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c_1>>s_1>>c_2>>s_2;
    if(c_1==c_2) f_1=1;
    if(f_1 && s_1[0]==s_2[0] &&s_1[1]==s_2[1]) f_2=1;
	if(f_1 && f_2 && (((s_1[2]=='A' || s_1[2]=='B' || s_1[2]=='C') && (s_2[2]=='A' || s_2[2]=='B' || s_2[2]=='C')) || (s_1[2]=='D' || s_1[2]=='E') && (s_1[2]=='D' || s_1[2]=='E'))) f_3=1;
	if(f_1 && f_2 && f_3){
		if(s_1[2]=='A' && s_2[2]=='B') f_4=1;
		else if(s_1[2]=='B' && s_2[2]=='C') f_4=1;
		else if(s_1[2]=='D' && s_2[2]=='F') f_4=1;
		else if(s_1[2]=='B' && s_2[2]=='A') f_4=1;
		else if(s_1[2]=='C' && s_2[2]=='B') f_4=1;
		else if(s_1[2]=='F' && s_2[2]=='D') f_4=1;
	}
	cout<<f_1<<f_2<<f_3<<f_4;
    return 0;
}
