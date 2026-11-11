#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,l1,l2;
	char s1,s2;
	string C1;
	string C2;
	string S1;
	string S2;
	cin>>C1>>S1>>C2>>S2;
	l1=(S1[0]-48)*10+(S1[1]-48);
	l2=(S2[0]-48)*10+(S2[1]-48);
	c1=(C1[0]-48)*10+(C1[1]-48);
	c2=(C2[0]-48)*10+(C2[1]-48);
	s1=S1[2];
	s2=S2[2];
	if(c1==c2){
		cout<<1;
		if(l1==l2){
			cout<<1;
			if((s1=='A')&&(s2=='B')) cout<<11;
			else if((s1=='B')&&(s2=='A')) cout<<11;
			else if((s1=='B')&&(s2=='C')) cout<<11;
			else if((s1=='C')&&(s2=='B')) cout<<11;
			else if((s1=='D')&&(s2=='F')) cout<<11;
			else if((s1=='F')&&(s2=='D')) cout<<11;
			else if((s1=='A')&&(s2=='C')) cout<<10;
			else if((s1=='C')&&(s2=='A')) cout<<10;
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
