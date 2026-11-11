#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2; 
char S1,S2;
void check(){
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(!( (S1=='D'&&S2=='C') || (S2=='D'&&S1=='C') )){
				cout<<"1";
				if(abs(S1-S2)==1||(S1=='D'&&S2=='F')||(S1=='F'&&S2=='D')) cout<<"1"; 
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&s1,&S1,&c2,&s2,&S2);
	check();
	return 0; 
}
