#include<bits/stdc++.h>
using namespace std;
string a,b;
char c,d,e,f,g,h;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>d>>e>>b>>f>>g>>h;
	if(a==b) {
		cout<<1;
		if(c==f&&d==g) {
			cout<<1;
			if((e=='D'&&h=='F')||(e=='F'&&h=='D')||(e=='A'&&(h=='B'||h=='C'))||(e=='B'&&(h=='A'||h=='C'))||(e=='C'&&(h=='B'||h=='A'))) {
				cout<<1;
				if((e=='D')||(e=='F')||(e=='B')||(h=='B')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
