#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[1];
	char b=s1[2];
	char c=s2[1];
	char d=s2[2];
	if(c1==c2){
		cout<<1;
		if(a==c){
			cout<<1;
			if((b=='A'&&d=='B')||(b=='A'&&d=='C')||(d=='A'&&b=='B')||(d=='A'&&b=='C')||(b=='D'&&d=='F')||(b=='F'&&d=='D')){
				cout<<1;
				if((b=='A'&&d=='B')||(b=='B'&&d=='C')||(d=='A'&&b=='B')||(d=='B'&&b=='C')||(b=='D'&&d=='F')||(b=='F'&&d=='D')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
