#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s, t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> s >> c >> d >> t;
	if(a==c) cout << 1;
	else return cout << "0000",0;
	
	if(b==d) cout << 1;
	else return cout << "000",0;
	
	if(s=='F'&&t!='D') return cout << "00",0;
	else if(s=='D'&&t!='F') return cout << "00",0;
	else if(t=='D'&&s!='F') return cout << "00",0;
	else if(t=='F'&&s!='D') return cout << "00",0;
	else cout << 1;
	
	if(s=='F'&&t=='D') return cout << 1, 0;
	if(s=='B'||t=='B') return cout << 1, 0;
	return cout << 0,0;
}
