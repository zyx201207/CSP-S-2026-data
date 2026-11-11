#include <bits/stdc++.h>
using namespace std;
char r[3]={};
char x[3]={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	for(int i=0;i<3;i++){
		r[i]=c2[i];
	}
	for(int i=0;i<3;i++){
		x[i]=c4[i];
	}
	if(c1==c3){
		cout<<"1";
		if(r[0]==x[0] && r[1]==x[1]){
			cout<<"1";
			if(r[2]=='A' && x[2]=='B' || r[2]=='A' && x[2]=='C' || r[2]=='B' && x[2]=='C' || r[2]=='D' && x[2]=='F' || x[2]=='A' && r[2]=='B' || x[2]=='A' && r[2]=='C' || x[2]=='B' && r[2]=='C' || x[2]=='D' && r[2]=='F'){
				cout<<"1";
				if(r[2]=='A' && x[2]=='B' || r[2]=='B' && x[2]=='C' || r[2]=='D' && x[2]=='F' || x[2]=='A' && r[2]=='B' || x[2]=='B' && r[2]=='C' || x[2]=='D' && r[2]=='F'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
