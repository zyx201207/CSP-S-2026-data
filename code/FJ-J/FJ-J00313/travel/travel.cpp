#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;//³µÏáºÅ¡¢×ùÎ»ºÅ 
	if(c1==c2){
		cout<<1;
		int flag1=0,flag2=0;
		long long seat1=(s1[0]-'0')*10+s1[1]-'0';
		long long seat2=(s2[0]-'0')*10+s2[1]-'0';
		if(seat1==seat2){
			cout<<1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')flag1=1;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')flag2=1;
			if(flag1==flag2){
				cout<<1;
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2])cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}else cout<<"000";
		
	} else {
		cout<<"0000"; 
	}
	return 0;
} 
//RP++ 
