#include<bits/stdc++.h>
using namespace std;
long long c1,s1,c2,s2;
string ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>ss1>>c2>>ss2;
	s1=int(ss1[0]-'0')*10+int(ss1[1]-'0');
	s2=int(ss2[0]-'0')*10+int(ss2[1]-'0');
	if(c1!=c2)cout<<"0000";
	else{
		cout<<1;
		if(s1!=s2)cout<<"000";
		else{
			cout<<1;
			if(!((ss1[2]<='C'&&ss2[2]<='C')||(ss1[2]>'C'&&ss2[2]>'C'))){
				cout<<"00";
			}
			else{
				cout<<1;
			    if((ss1[2]=='A'&&ss2[2]=='B')||(ss1[2]=='B'&&ss2[2]=='A'))cout<<1;
			    else if((ss1[2]=='B'&&ss2[2]=='C')||(ss1[2]=='C'&&ss2[2]=='B'))cout<<1;
			    else if((ss1[2]=='D'&&ss2[2]=='F')||(ss1[2]=='F'&&ss2[2]=='D'))cout<<1;
			    else cout<<0;
			}
		}
	}
	return 0;
} 
