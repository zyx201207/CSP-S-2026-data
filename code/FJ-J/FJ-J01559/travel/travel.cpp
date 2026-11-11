#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char c1k,c2k;
	scanf("%d%d%c",&c1,&s1,&c1k);
	scanf("%d%d%c",&c2,&s2,&c2k);
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if((c1k=='A'&&(c2k=='B'||c2k=='C'))||(c1k=='B'&&(c2k=='A'||c2k=='C'))||(c1k=='C'&&(c2k=='B'||c2k=='A'))||(c1k=='D'&&c2k=='F')||(c1k=='F'&&c2k=='D')){
				cout<<"1";
				if((c1k=='A'&&c2k=='B')||(c1k=='B'&&(c2k=='A'||c2k=='C'))||(c1k=='C'&&c2k=='B')||(c1k=='D'&&c2k=='F')||(c1k=='F'&&c2k=='D')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
