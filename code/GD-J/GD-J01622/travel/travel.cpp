#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,a1,a2;
bool f=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				cout<<1;
				f=true;
			}
			else cout<<0;
		}else if(s1[2]=='F'||s1[2]=='D'){
			if(s2[2]=='F'||s2[2]=='D'){
				cout<<1;
				f=true;
			}
			else cout<<0;
		}
	}else cout<<0;
	if(f&&abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
} 
