#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n1,n2;
	char c1,c2;
	cin>>n1;
	cin>>c1;
	cin>>n2;
	cin>>c2;
	if(n1==n2){
		if(c1==c2) return 0;
		cout<<1;
		int n=(c1[0]-'0')*10+(c1[1]-'0');
		int m=(c2[0]-'0')*10+(c2[1]-'0');
		if(n==m) {
			cout<<1;
			char a=c1[2];
			char b=c2[2];
			if((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(a=='B'&&b=='A')||(a=='C'&&b=='A')||(a=='C'&&b=='B')||(a=='F'&&b=='D')) {
				cout<<1;
				if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(a=='B'&&b=='A')||(a=='C'&&b=='B')||(a=='F'&&b=='D')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<00;
			}
		}else{
			cout<<000;
		}
		
	}else{
		cout<<0000;
		return 0;
	}
	
	return 0;
}
