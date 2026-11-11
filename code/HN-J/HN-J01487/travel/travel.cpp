#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
string a,b,c,d;
bool chick(){
	char x=b[2],y=d[2];
	if(x=='A'&&(y=='B'||y=='C')) return 1;
	if(x=='B'&&(y=='A'||y=='C')) return 1;
	if(x=='C'&&(y=='A'||y=='C')) return 1;
	if(x=='D'&&y=='E') return 1;
	if(x=='E'&&y=='D') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		if(b.substr(0,2)==d.substr(0,2)){
			cout<<'1';
			if(chick()==1){
				cout<<'1';
				if(abs(b[2]-d[2])==1) cout<<'1';
				else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}


