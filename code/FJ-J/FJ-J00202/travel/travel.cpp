#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char x='Z',y='Z';
			for(char c='A';c<='C';c++){
				if(c==s1[2]){
					x=c;
				}
				if(c==s2[2]){
					y=c;
				}
			}
			if((x!='Z'&&y!='Z')||(x=='Z'&&y=='Z')){
				cout<<1;
				if(x=='Z'&&y=='Z'){
					cout<<1;
				}else if((x=='A'&&y=='B')||(x=='B'&&y=='C')){
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
//02 01A 02 01B
