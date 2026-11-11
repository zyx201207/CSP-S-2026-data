#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char a=s1[2],b=s2[2];
			LL x=0,y=0;
			if(a=='A'||a=='B'||a=='C') x=1;
			if(b=='A'||b=='B'||b=='C') y=1;
			if(x==y){
				cout<<1;
				LL p,q;
				if(a=='A') p=1;
				else if(a=='B') p=2;
				else if(a=='C') p=3;
				else if(a=='D') p=4;
				else if(a=='F') p=5;
				if(b=='A') p=1;
				else if(b=='B') q=2;
				else if(b=='C') q=3;
				else if(b=='D') q=4;
				else if(b=='F') q=5;
				if(p-1==q||p+1==q) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
