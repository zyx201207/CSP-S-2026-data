#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	bool samero;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) samero=1;
	else samero=0;
	cout<<samero;
	char apos=s1[2],bpos=s2[2];
	bool samesid;
	if(samero&&((apos=='A'&&bpos=='C')||(apos=='C'&&bpos=='A')||(apos=='B'&&bpos=='C')||(apos=='C'&&bpos=='B')||(apos=='A'&&bpos=='B')||(apos=='B'&&bpos=='A')||(apos=='D'&&bpos=='F')||(apos=='F'&&bpos=='D'))) samesid=1;
	else samesid=0;
	cout<<samesid;
	if(samesid&&((apos=='A'&&bpos=='B')||(apos=='B'&&bpos=='A')||(apos=='B'&&bpos=='C')||(apos=='C'&&bpos=='B')||(apos=='D'&&bpos=='F')||(apos=='F'&&bpos=='D'))) cout<<"1";
	else cout<<"0";
	return 0;
}
	
