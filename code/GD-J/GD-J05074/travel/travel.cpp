#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('travel.in','r',stdin);
	freopen('travel.out','w',stdout);
	string c,s,cc,ss;
	cin>>c;
	cin>>s;
	cin>>cc;
	cin>>ss;
	if(c==cc){
		cout<<1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<"1";
			if((s[2]=='A'&&ss[2]=='B')||(s[2]=='A'&&ss[2]=='C')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='A')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='E')||(s[2]=='E'&&ss[2]=='D')){
				cout<<"1";
				if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='E'&&ss[2]=='D')||(s[2]=='D'&&ss[2]=='E')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}		
		}else{
			cout<<"000";
		}
		
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}
