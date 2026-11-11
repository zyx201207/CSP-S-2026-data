#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char x=s1[2],y=s2[2];
	int x1=(s1[0]-'0')*10+(s1[1]-'0');
	int y1=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2){
		cout<<1;
		if(x1==y1){
			cout<<1;
			if(x<='C'&&y<='C'){
				cout<<1;
				if(x+1==y||y+1==x) cout<<1;
				else cout<<0;
			}
			else if(x>='D'&&y>='D') cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
