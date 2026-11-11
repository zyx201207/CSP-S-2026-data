#include<bits/stdc++.h>
using namespace std;
string r1,x1;
int r2[4],x2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c;
	cin>>r1;
	for(int i=1;i<=2;i++){
		cin>>c;
		r2[1]=r2[1]*10+(c-'0');
	}
	cin>>c;
	r2[2]=(c-'A')+1;
	if(r2[2]==4) r2[2]++;
	
	cin>>x1;
	for(int i=1;i<=2;i++){
		cin>>c;
		x2[1]=x2[1]*10+(c-'0');
	}
	cin>>c;
	x2[2]=(c-'A')+1;
	if(x2[2]==4) x2[2]++;
	
	if(r1!=x1){
		cout<<"0000";
	}	
	else if(r2[1]!=x2[1]){
		cout<<"1000";
	}
	else if(!((r2[2]<=3&&x2[2]<=3)||(r2[2]>=5&&x2[2]>=5))){
		cout<<"1100";
	}
	else if(abs(r2[2]-x2[2])!=1){
		cout<<"1110";
	}
	else{
		cout<<"1111"; 
	}
	return 0;
}
