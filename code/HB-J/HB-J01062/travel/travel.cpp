#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1) cout<<1;
	else{
		cout<<"0000";
		return 0;}
	if(r2[0]==x2[0] && r2[1]==x2[1]) cout<<1;
	else{
		cout<<"000";
		return 0;}
	if((r2[2]=='D' && x2[2]=='F') or (r2[2]=='F' && x2[2]=='D'))cout<<1;
	else{
		if((r2[2]!='D' && r2[2]!='F') and (x2[2]!='D' && x2[2]!='F'))cout<<1;
		else{
			cout<<"00";
			return 0;}}
	if((r2[2]=='D' && x2[2]=='F') or (r2[2]=='F' && x2[2]=='D'))cout<<1;
	else{
		if(r2[2]=='A' or r2[2] =='C'){
			if(x2[2]=='B') cout<<1;
			else cout<<0;}
		else if(r2[2]=='B'){
			if(x2[2]=='A' or x2[2]=='C') cout<<1;
			else cout<<0;}}
	return 0;
	}
