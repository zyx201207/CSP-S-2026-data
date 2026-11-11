#include<bits/stdc++.h>

using namespace std;
string ra,rb,xa,xb;
bool check(char c,char d){
	if((c=='F'&&d=='D')||(c=='D'&&d=='F')||(c=='A'&&d=='B')
	||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')||
	(c=='A'&&d=='C')||(c=='C'&&d=='A'))return 1;
	else return 0;
}
bool check1(char c,char d){
	if((c=='F'&&d=='D')||(c=='D'&&d=='F')||(c=='A'&&d=='B')
	||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')
	)return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",sdtin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>ra>>rb>>xa>>xb;
	if(ra==xa){
		cout<<1;
	}
	else cout <<0;
	string a = rb.substr(0,2);
	string b = xb.substr(0,2);
	if(a==b&&ra==xa)cout <<1;
	else cout <<0;
	if(a==b&&ra==xa&&check(rb[2],xb[2]))cout<<1;
	else cout <<0;
	if(a==b&&ra==xa&&check(rb[2],xb[2])&&check1(rb[2],xb[2]))cout <<1;
	else cout <<0;
	return 0;
}

