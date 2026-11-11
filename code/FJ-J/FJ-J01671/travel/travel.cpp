#include<bits/stdc++.h>
using namespace std;
int zzl(char a,char b){
	if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C')){
		return 1;
	}
	if((a=='D' || a=='F') && (b=='D' || b=='F')){
		return 1;
	}
	return 0;
}
int zzl2(char a,char b){
	if((a=='A' || a=='B') && (b=='A' || b=='B')){
		return 1;
	}
	if((a=='C' || a=='B') && (b=='C' || b=='B')){
		return 1;
	}
	if((a=='D' || a=='F') && (b=='D' || b=='F')){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3],b;
	cin>>c1[0]>>c1[1];
	cin>>s1[0]>>s1[1]>>s1[2];
	cin>>c2[0]>>c2[1];
	cin>>s2[0]>>s2[1]>>s2[2];
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if(zzl(s1[2],s2[2])){
				cout<<1;
				if(zzl2(s1[2],s2[2])){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
		
	}
	else cout<<"0000";
	
	
	
	
	
	return 0;
}

