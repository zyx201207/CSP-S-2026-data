#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int c11,c33;
	c11+=(c1[0]-'0')*10;
	c33+=(c3[0]-'0')*10;
	c11+=c1[1]-'0';
	c33+=c3[1]-'0';
//	cout<<c11<<c33;
	if(c11==c33){
		cout<<1;
		int c22,c44;
		c22+=(c2[0]-'0')*10;
		c44+=(c4[0]-'0')*10;
		c22+=c2[1]-'0';
		c44+=c4[1]-'0';
		if(c22==c44){
			cout<<1;
			char a=c2[2];
			char b=c4[2];
			if(a=='A'&&b=='B'||a=='A'&&b=='C'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='A'||
			a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
				cout<<1;
				if(abs(a-b)==1){
					cout<<1<<'\n';
				}else{
					cout<<0<<'\n';
				}
			}else{
				cout<<"00"<<'\n';
				return 0;
			}
		}else{
			cout<<"000"<<'\n';
		}
	}else{
		cout<<"0000"<<'\n';
		return 0;
	}
	return 0;
} 
