#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string cr,cx,sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(sr[2]<=66&&sx[2]<=66){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(sr[2]<=66&&sx[2]<=66){
		cout<<'1';
	}else if(sr[2]>=67&&sx[2]>=67){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(sr[2]==sx[2]+1||sr[2]==sx[2]-1){
		cout<<'1';
	}else{
		cout<<'0';
		return 0;
	}
	return 0;
}
