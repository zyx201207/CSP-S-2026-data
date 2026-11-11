#include<bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
str c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			char r=s1[2],x=s2[2];
			if(((r=='F' and x=='D') or (r=='D' and x=='F'))/*FD*/ or ((r=='A' and x=='B') or (r=='B' and x=='C') or (r=='C' and x=='A'))){
				cout<<1;
				if(((r=='F' and x=='D') or (r=='D' and x=='F')) or ((r=='A' and x=='B') or (r=='B' and x=='A')) or ((r=='C' and x=='B') or (r=='B' and x=='C'))){
					cout<<1;
				}else{
					cout<<0;
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
