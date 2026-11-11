#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s1[N],s2[N];
int a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=1;
	if(s1[0]==s2[0] && s1[1]==s2[1] && a==1) b=1;
	if(a==1 && b==1){
		if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='A')) c=1;
		else if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B')) c=1;
		else if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) c=1;
	}
	if(b==1){
		if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F')) d=1;
		else if((s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='F' && s2[2]=='D')) d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
