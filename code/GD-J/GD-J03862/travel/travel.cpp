#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int zz;
bool pd(char x,char y){
	if(x=='A'||x=='B'||x=='C') return (y=='A'||y=='B'||y=='C');
	return (y=='D'||y=='F');
}
bool pdd(char x,char y){
	if(x=='A') return (y=='B');
	if(x=='B') return (y=='A'||y=='C');
	if(x=='C') return (y=='B');
	if(x=='D') return (y=='F');
	return (y=='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(pd(b[2],d[2])){
				if(pdd(b[2],d[2])) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	
	return 0;
}
