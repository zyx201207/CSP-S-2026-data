#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		char a1=s1[0],a2=s1[1],a3=s2[0],a4=s2[1];
		if(a1==a3&&a2==a4){
			cout<<1;
			char a=s1[2];
			char b=s2[2];
			if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='B'&&b=='A'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'||a=='A'&&b=='C'||a=='C'&&b=='A'){
				cout<<1;
				if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='B'&&b=='A'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	
	
	return 0;
}
