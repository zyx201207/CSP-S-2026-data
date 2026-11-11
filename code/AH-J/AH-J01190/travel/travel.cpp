#include<bits/stdc++.h>
using namespace std;
string a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1;
	getchar();
	char an1=getchar();
	char an2=getchar();
	char ach=getchar();
	getchar();
	cin>>b1;
	getchar();
	char bn1=getchar();
	char bn2=getchar();
	char bch=getchar();

	if(a1==b1){
		cout<<1;
		int tp1=(an1-'0')*10+(an2-'0'),tp2=(bn1-'0')*10+(bn2-'0');
		if(tp1==tp2){
			cout<<1;
			if(((ach=='A'||ach=='B'||ach=='C')&&(bch=='A'||bch=='B'||bch=='C'))||((ach=='D'||ach=='F')&&(bch=='D'||bch=='F'))&&ach!=bch){
				cout<<1;
				char a=ach,b=bch;
				if((a=='A'&&b=='B')||(a=='B'&&(b=='C'||b=='A'))||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'||b=='D'))
					cout<<1;
				else 
					cout<<0;
			}else
				cout<<"00";
		}else 
			cout<<"000";
	}else 
		cout<<"0000";
	
	return 0;
}

