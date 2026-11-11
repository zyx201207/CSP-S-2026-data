#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	cout<<(c==cc);
	cout<<(c==cc&&s[0]+s[1]==ss[0]+ss[1]);
	cout<<(c==cc&&s[0]+s[1]==ss[0]+ss[1]&&((s[2]=='A'&&ss[2]=='B')||(s[2]=='A'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='F')||(ss[2]=='A'&&s[2]=='B')||(ss[2]=='A'&&s[2]=='C')||(ss[2]=='C'&&s[2]=='B')||(ss[2]=='D'&&s[2]=='F')));
	cout<<(c==cc&&s[0]+s[1]==ss[0]+ss[1]&&((s[2]=='A'&&ss[2]=='B')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='D'&&ss[2]=='F')||(ss[2]=='A'&&s[2]=='B')||(ss[2]=='C'&&s[2]=='B')||(ss[2]=='D'&&s[2]=='F')));
    return 0;
}
