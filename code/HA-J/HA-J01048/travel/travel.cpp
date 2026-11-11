#include<bits/stdc++.h>
using namespace std;
string r_1,r_2,x_1,x_2;
string rp,rl,xp,xl;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	
	cin>>r_1>>r_2>>x_1>>x_2;
	if(r_1==x_1)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	
	rp+=r_2[0]+r_2[1],rl+=r_2[2];
    xp+=x_2[0]+x_2[1],xl+=x_2[2];
	if(rp==xp)cout<<"1";
	else {
		
		cout<<"000";
		return 0;
	}
	if(rl[0]<='C' and xl[0]<='C')cout<<"1";
	else {
	cout<<"00";
	return 0;
	}
	if(rl[0]+1==xl[0] or rl[0]==xl[0])cout<<"1";
	else cout<<"0";
	return 0;
}
