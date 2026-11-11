#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=s1[2],y=s2[2];
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]){
			if(s1[1]==s2[1]){
				cout<<"1";
				if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')){
					cout<<"1";
					if((x+1==y)||(x-1==y)) cout<<"1";
					else cout<<"0";
				}else if((x=='F'||x=='D')&&(x=='D'||x=='F')){
					cout<<"1";
					if((x+1==y)||(x-1==y)) cout<<"1";
					else cout<<"0";
				}else{
					cout<<"00";
				}
			}else{
				cout<<"000";
			}
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
