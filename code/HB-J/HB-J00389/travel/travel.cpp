#include<bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2;
bool b1,b2,b3,b4;
char is_xianglin(char a,char b){
	if(a>b) swap(a,b);
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='D'&&b=='F') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	b1=(C1==C2);
	b2=(b1&&(S1.substr(0,2)==S2.substr(0,2)));
	b3=(b2&&((('A'<=S1[2]&&S1[2]<='C')==('A'<=S2[2]&&S2[2]<='C'))));
	b4=(b3&&is_xianglin(S1[2],S2[2]));
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
