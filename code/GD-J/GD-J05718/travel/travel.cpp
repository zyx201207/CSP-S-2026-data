#include<bits/stdc++.h>
using namespace std;
string ra,rb,rc,xa,x2,xc;
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	cin>>ra>>rb>>xa>>x2;
	rc+=rb[0];
	rc+=rb[1];
	xc+=x2[0];
	xc+=x2[1];
	cout<<(ra==xa);
	cout<<(rc==xc);
	cout<<((rb[2]=='F'&&x2[2]=='D')||(rb[2]=='D'&&x2[2]=='F')||(rb[2]<='C'&&x2[2]<='C'));
	cout<<((rb[2]=='F'&&x2[2]=='D')||(rb[2]=='D'&&x2[2]=='F')||(!(rb[2]=='C'&&x2[2]=='D')&&(rb[2]==x2[2]-1||rb[2]==x2[2]+1)));
	return 0;
}
