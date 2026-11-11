#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int s1,s2;
/*bool cmp(p x,p y){
	if(x.c==y.c) cout<<"1";
	else cout<<"0";
	if(x.s/10==y.s/10) cout<<"1";
	else cout<<"0";
	if(x.s%10=='D' || x.s%10=='F' && y.s%10=='D' || y.s%10=='F') cout<<"1";
	else if(x.s%10=='A' || x.s%10=='B' || x.s%10=='C' && y.s%10=='A' || y.s%10=='B' || y.s%10=='C')
	cout<<"1";
	else cout<<"0";
	if(x.s%10=='D' && x.s%10=='F') cout<<"1";
	else if(x.s%10=='F' && x.s%10=='D') cout<<"1";
	else if(x.s%10=='A' && x.s%10=='B') cout<<"1";
	else if(x.s%10=='B' && x.s%10=='C') cout<<"1";
	else if(x.s%10=='B' && x.s%10=='A') cout<<"1";
	else if(x.s%10=='C' && x.s%10=='B') cout<<"1";
	else cout<<"0";
};*/
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel,out","w",stdout);
	cin>>c1>>s1>>c2>>c2;
	if(c2%10==c1%10) cout<<"1";
	else cout<<"0";
	
	if(s1/10==s2/10) cout<<"1";
	else cout<<"0";
	
	if(s1%10=='D' && s2%10=='F') cout<<"1";
	else if(s2%10=='D' && s1%10=='F') cout<<"1";
	else if(s1%10=='A' && s2%10=='B') cout<<"1";
	else if(s2%10=='C' && s1%10=='A') cout<<"1";
	else if(s2%10=='C' && s1%10=='B') cout<<"1";
	else if(s2%10=='A' && s1%10=='B') cout<<"1";
	else if(s1%10=='C' && s2%10=='A') cout<<"1";
	else if(s1%10=='C' && s2%10=='B') cout<<"1";
	else cout<<"0";
	
	if(s1%10=='D' && s2%10=='F' || s1%10=='F' && s2%10=='D') cout<<"1";
	else if(s1%10=='A' && s2%10=='B' || s1%10=='B' && s2%10=='C') cout<<"1";
	else if(s1%10=='B' && s2%10=='A' || s1%10=='C' && s2%10=='B') cout<<"1";
	else cout<<"0";	
	return 0;
}
