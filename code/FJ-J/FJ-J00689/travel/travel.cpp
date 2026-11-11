#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>ss1>>ss2;
	if(s1==ss1){
		cout<<1;
		if(s2[0]==ss2[0]&&s2[1]==ss2[1]){
			cout<<1;
			if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(ss2[2]=='A'||ss2[2]=='B'||ss2[2]=='C'))||((s2[2]=='D'||s2[2]=='E')&&(ss2[2]=='D'||ss2[2]=='E'))){
				cout<<1;
				if((s2[2]=='A'&&ss2[2]=='B')||(ss2[2]=='A'&&s2[2]=='B')||(s2[2]=='C'&&ss2[2]=='B')||(ss2[2]=='C'&&s2[2]=='B')||(s2[2]=='D'&&ss2[2]=='F')||(ss2[2]=='D'&&s2[2]=='F')){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	
}
