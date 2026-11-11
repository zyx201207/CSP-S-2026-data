#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char a,b;
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if((a=='F'||a=='D')&&(b=='F'||b=='D')){
				cout<<"11";
			}else if(((a=='F'||a=='D')&&(b=='A'||b=='B'||b=='C'))||((b=='F'||b=='D')&&(a=='A'||a=='B'||a=='C'))){
				cout<<"00";
			}else{
				cout<<"1";
				if(a-b==1||b-a==1)cout<<"1";
				else cout<<"0";
			}
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
