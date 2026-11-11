#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(sr[0]!=sx[0]||sr[1]!=sx[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	bool f=false;
	char c1=sr[2],c2=sx[2];
	if(c1>='A'&&c1<='C'&&c2>='A'&&c2<='C') f=true;
	else if(c1>='D'&&c1<='F'&&c2>='D'&&c2<='F') f=true;
	if(!f){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(c1<c2) swap(c1,c2);
	if(c1-1!=c2){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
} 
