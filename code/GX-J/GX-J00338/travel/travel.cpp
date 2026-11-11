#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string al,bl;
	cin>>a1>>al>>b1>>bl;
	if(a1==b1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(al[0]==bl[0]&&al[1]==bl[1]) cout<<1;
	else{
		cout<<"000";
		return 0;}
	char a=al[2],b=bl[2];
	bool az=(a=='A'||a=='B'||a=='C');
	bool bz=(b=='A'||b=='B'||b=='C');
	if(az==bz) cout<<1;
	else{
		cout<<"00";
		return 0;}
	if(a-b==1||a-b==-1) cout<<1;
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
