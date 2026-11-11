#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c2[4],c4[4];
	int c1,c3;
	cin>>c1;
	cin>>c2;
	cin>>c3;
	cin>>c4;

	if(c1==c3)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(c2[1]+c2[0]==c4[0]+c4[1]){
		cout<<1;
		if((((c2[2]=='A')||(c2[2]=='B')||(c2[2]=='C'))&&((c4[2]=='A')||(c4[2]=='B')||(c4[2]=='C')))||(((c2[2]=='D')||(c2[2]=='F'))&&((c4[2]=='D')||(c4[2]=='F')))){
			cout<<1;
			if((c2[2]=='F'||c2[2]=='D')||(c2[2]=='B'||c4[2]=='B'))
				cout<<1;
			else
				cout<<0;;
		}
		else
			cout<<"00";
	}
	else
		cout<<"000";
}
