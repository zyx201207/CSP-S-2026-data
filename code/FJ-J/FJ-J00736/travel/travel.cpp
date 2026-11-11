#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
char c,d;
int a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb) {
		cout<<"1";
		a=(sa[0]-'0')*10+(sa[1]-'0');
		b=(sb[0]-'0')*10+(sb[1]-'0');
		if(a==b) {
			cout<<"1";
			c=sa[2];
			d=sb[2];
			if((c<='C'&&d<='C')||(c>='D'&&d>='D')) {
				cout<<"1";
				if((c-1==d||c+1==d)||((c=='D'&&d=='F')||(c=='F'&&d=='D')))cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
