#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a1,a2,b1,b2;
	char a,b;
	char c,c1;
	
	scanf("%c%c",&c,&c1);
	a1=(c-'0')*10+(c1-'0');
	scanf(" %c%c",&c,&c1);
	a2=(c-'0')*10+(c1-'0');
	scanf("%c",&a);
	
	scanf(" %c%c",&c,&c1);
	b1=(c-'0')*10+(c1-'0');
	scanf(" %c%c",&c,&c1);
	b2=(c-'0')*10+(c1-'0');
	scanf("%c",&b);
	
	if(a1==b1){
		cout<<"1";
		if(a2==b2){
			cout<<"1";
			if((a=='F'&&b=='D')||(a=='D'&&b=='F')||(a!='D'&&b!='D'&&a!='F'&&b!='F')){
				cout<<"1";
				if(abs(a-b)==1){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
