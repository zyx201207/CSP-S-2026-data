#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,s3,s4;
int s11,s21;
char s12,s22;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	s11=(s1[0]-'0')*10+(s1[1]-'0');
	s21=(s2[0]-'0')*10+(s2[1]-'0');
	s12=s1[2];
	s22=s2[2];
	if(c1==c2){
		cout<<1;
		if(s11==s21){
			cout<<1;
			if(abs(s12-s22)<=2){
				if(s12=='C'&&s22=='D') cout<<0<<0;
				else if(s12=='D'&&s22=='C') cout<<0<<0;
				else if(s12=='B'&&s22=='D') cout<<0<<0;
				else if(s12=='D'&&s22=='B') cout<<0<<0;
				}else {
					cout<<1;
					if(s12=='A'&&s22=='B') cout<<1;
					else if(s12=='B'&&s22=='A') cout<<1;
					else if(s12=='B'&&s22=='C') cout<<1;
					else if(s12=='C'&&s22=='B') cout<<1;
					else if(s12=='D'&&s22=='F') cout<<1;
					else if(s12=='F'&&s22=='D') cout<<1;
					else cout<<0;
				}
				
			}
			
		else{
			cout<<0<<0<<0;
		}
		
		
	}else{
		cout<<0<<0<<0<<0;

	}
	return 0;
}
