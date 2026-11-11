#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,zwh1,cx2,zwh2;
	cin>>cx1>>zwh1>>cx2>>zwh2;
	if(cx1!=cx2){
		cout<<"0000";
		return 0;
	}else cout<<1;
	if(zwh1[0]==zwh2[0]&&zwh1[1]==zwh2[1])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if(zwh1[2]=='A'||zwh1[2]=='B'||zwh1[2]=='C'){
		if(zwh2[2]=='A'||zwh2[2]=='B'||zwh2[2]=='C')cout<<1;
		else{
			cout<<"00";
			return 0;
		} 
		int a=int(zwh1[2]),b=int(zwh2[2]);
		if(abs(a-b)==1)cout<<1;
		else{
			cout<<0;
			return 0;
		}
	}
	if(zwh1[2]=='D'||zwh1[2]=='F'){
		if(zwh2[2]=='D'||zwh2[2]=='F'){
			cout<<11;
		}else cout<<0;
	}
	
	return 0;
}
//continue;		
