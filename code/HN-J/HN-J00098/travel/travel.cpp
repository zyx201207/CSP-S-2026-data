#include<bits/stdc++.h>
using namespace std;
char gg[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		gg[i]='0';
	}
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		gg[1]='1';
	}
	if(gg[1]=='1'&&c2[0]==c4[0]&&c2[1]==c4[1]){
		gg[2]='1';
	}
	if(gg[2]=='1'&&c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C'||gg[2]=='1'&&c2[2]>='D'&&c2[2]<='F'&&c4[2]>='D'&&c4[2]<='F'){
		gg[3]='1';
	}
	if(gg[3]=='1'&&c2[2]-1==c4[2]||gg[3]=='1'&&c4[2]-1==c2[2]){
		gg[4]='1';
	}
	for(int i=1;i<=4;i++){
		cout<<gg[i];
	}
} 
