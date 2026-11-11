#include<bits/stdc++.h>
using namespace std;
int c,c1;
char s[5],s1[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c;
	for(int i=1;i<=3;i++){
		cin>>s[i];
	}
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	if(c==c1){
		cout<<1;
		if(s[1]==s1[1]&&s[2]==s1[2]){
			cout<<1;
			if((s[3]=='A'&&s1[3]=='B')||(s1[3]=='A'&&s[3]=='B')){
				cout<<11;
			}else if((s[3]=='A'&&s1[3]=='C')||(s1[3]=='A'&&s[3]=='C')){
				cout<<10;
			}else if((s[3]=='B'&&s1[3]=='C')||(s1[3]=='B'&&s[3]=='C')){
				cout<<11;
			}else if((s[3]=='D'&&s1[3]=='F')||(s1[3]=='D'&&s[3]=='F')){
				cout<<11;
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
