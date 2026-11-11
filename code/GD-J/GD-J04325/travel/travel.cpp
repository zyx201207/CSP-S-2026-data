#include<bits/stdc++.h>
using namespace std;
char S1[3],S2[3];
string C1,C2;
bool flag=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C1>>S2;
	if(C1==C2) printf("%d",1);
	else printf("%d",0);
	if(S1[0]==S2[0]&&S1[1]==S2[1])printf("%d",1);
	else printf("%d",0);
	if((S1[2]<='C'&&S2[2]<='C')||(S1[2]>'C'&&S2[2]>'C')){printf("%d",1); flag=true;}
	else printf("%d",0);
	if(flag&&(S1[2]+1==S2[2]+0||S1[2]-1==S2[2]+0))printf("%d",1);
	else printf("%d",0);
	return 0;
} 
