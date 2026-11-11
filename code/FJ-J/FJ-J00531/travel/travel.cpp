#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2,line1,line2;
	char a,b;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&c1,&line1,&a,&c2,&line2,&b);
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else cout<<1;
	if(line1!=line2){
		cout<<0<<0<<0;
		return 0;
	}
	else cout<<1;
	if(((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='A')||(a=='C'&&b=='B'))||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
		cout<<1;
		if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))cout<<1; 
		else cout<<0;
	}
	else cout<<0<<0;
	
	return 0;
}
