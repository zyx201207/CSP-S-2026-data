#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	int r=r2[2]-'A'+1,x=x2[2]-'A'+1;
	if(r==6){
		r--;
	}
	if(x==6){
		x--;
	}
	if(((r1[0]-'0')*10+r1[1]-'0')==((x1[0]-'0')*10+x1[1]-'0')){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(((r2[0]-'0')*10+r2[1]-'0')==((x2[0]-'0')*10+x2[1]-'0')){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	int cr=0,cx=0;
	if(r>3){
		cr=1;
	}
	if(x>3){
		cx=1;
	}
	if(cr==cx){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(r-1==x||r+1==x){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	return 0;
}
