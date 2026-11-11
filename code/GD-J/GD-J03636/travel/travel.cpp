#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2,x,xx;
char y,yy;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		x+=s1[0];
		x+=s1[1];
		xx+=s2[0];
		xx+=s2[1];
		y=s1[2];
		yy=s2[2];
		if(x==xx) {
			cout<<1;
			if(y<='C'&&yy<='C'){
				cout<<1;
				if(abs(y-yy)==1) cout<<1;
				else cout<<0;
			}
			else if(y>='D'&&yy>='D'){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}




	return 0;
}

