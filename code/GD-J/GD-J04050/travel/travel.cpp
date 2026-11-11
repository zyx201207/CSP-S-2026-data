#include<bits/stdc++.h>
using namespace std;

int which_side(char a){
	return ((a<='C')?1:0);
}
bool near_by(char a,char b){
	if(a=='A' && (b=='B')) return true;
	if(a=='B' && (b=='A' || b=='C')) return true;
	if(a=='C' && (b=='B')) return true;
	if(a=='D' && (b=='F')) return true;
	if(a=='F' && (b=='D')) return true;
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2){
		cout<<"0000"<<'\n';
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"1000"<<'\n';
		return 0;
	}
	if(which_side(s1[2]) != which_side(s2[2])){
		cout<<"1100"<<'\n';
		return 0;
	}
	if(!near_by(s1[2],s2[2])){
		cout<<"1110"<<'\n';
		return 0;
	}
	cout<<"1111"<<'\n';
	return 0;
}
/*
//freopen("travel.in","r",stdin);
freopen("travel4.in","r",stdin);
Trcik || Treat !
*/
