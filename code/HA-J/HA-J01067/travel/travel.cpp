#include<bits/stdc++.h>
using namespace std;
struct s{
	int a;
	string s;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s b[10];
	for(int i=1;i<=2;i++){
		cin>>b[i].a>>b[i].s;
	}
	int j=2;
	while(j>=0){
		if(b[j].s[2]=='A') b[j].s[2]=1;
		else if(b[j].s[2]=='B') b[j].s[2]=2;
		else if(b[j].s[2]=='C') b[j].s[2]=3;
		else if(b[j].s[2]='D') b[j].s[2]=4;
		else b[j].s[2]=5;
		j--;
	}
	string c[10];
	for(int i=1;i<=2;i++){
		
	}
	if(b[1].a==b[2].a){
		cout<<"1";
		if(b[1].s[0]==b[2].s[0]&&b[1].s[1]==b[2].s[1]){
			cout<<"1";
				if((b[1].s[2]<=3&&b[2].s[2]<=3)||(b[1].s[2]>=4&&b[2].s[2]>=4)){
				cout<<"1";
					if((b[1].s[2]!=3&&b[1].s[2]==b[2].s[2]-1)||(b[1].s[2]!=4&&b[1].s[2]==b[2].s[2]+1)){
					cout<<"1";}
			else cout<<"0";}
			else cout<<"00";}
			else cout<<"000";}
	else cout<<"0000";
	
	
	
	return 0;
}
