#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 cin>>cr>>sr>>cx>>sx;
	 if(cr==cx)cout<<'1';
	 else{
	 	cout<<"0000";
	 	return 0;
	 }
	 if(sr[1]==sx[1]&&sr[0]==sx[0])cout<<'1';
	 else{
	 	cout<<"000";
	 	return 0;
	 }
	 if(sr[2]>='A'&&sr[2]<='C' && sx[2]>='A'&&sx[2]<='C'||sr[2]>='D'&&sr[2]<='F' && sx[2]>='D'&&sx[2]<='F')cout<<'1';
	 else{
	 	cout<<"00";
	 	return 0;
	 }
	 if(sr[2]+1==sx[2]||sx[2]+1==sr[2]||sr[2]=='D'&&sx[2]=='F'||sr[2]=='F'&&sx[2]=='D')cout<<'1';
	 else{
	 	cout<<'0';
	 	return 0;
	 }
}
