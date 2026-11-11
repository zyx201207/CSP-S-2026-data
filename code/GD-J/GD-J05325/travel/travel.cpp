#include<bits/stdc++.h>
using namespace std;
int c1,c2,S1,S2;
string s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	S1=(s1[0]-'0')*10+s1[1]-'0';
	S2=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2){
		cout<<1;
		if(S1==S2){
			cout<<1;
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='c'))||(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))){
				cout<<1<<(abs(s1[2]-s2[2])==1?1:0);
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 

