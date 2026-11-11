#include<bits/stdc++.h>
using namespace std;

int c_1,c_2;
string s_1,s_2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	if((s_1[0]==s_2[0])&&(s_1[1]==s_2[1])) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	char S_1=s_1[2],S_2=s_2[2];
	if((((S_1=='A'||S_1=='B'||S_1=='C') && (S_2=='A'||S_2=='B'||S_2=='C'))) || ((S_1=='D'||S_1=='F') && (S_2=='D'||S_2=='F'))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	
	if((abs(S_1-S_2)==1) || ((S_1=='D'||S_1=='F') && (S_2=='D'||S_2=='F'))) cout<<1;
	else
		cout<<"0";
	
	return 0;
}
