//GZ-J00461 สตั้ศý ั๎ฯ่๎ฃ 
#include <bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
bool fa,fb,fc,fd;
bool check(char a,char b){
	if( (a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C') ) return 0;
	if( (a=='D' || a=='F') && (b=='D' || b=='F') ) return 0;
	return 1;
}
bool func(char a,char b){
	if(a=='A' && b=='B') return 0;
	if(a=='B' && b=='A') return 0;
	if(a=='B' && b=='C') return 0;
	if(a=='C' && b=='B') return 0;
	if(a=='D' && b=='F') return 0;
	if(a=='F' && b=='D') return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb){
		cout<<fa<<fb<<fc<<fd;
		return 0;
	}
	else fa=1;
	char saa=sa[0],sab=sa[1],sac=sa[2];
	char sba=sb[0],sbb=sb[1],sbc=sb[2];
	if(saa!=sba || sab!=sbb){
		cout<<fa<<fb<<fc<<fd;
		return 0;
	}
	else fb=1;
	if(check(sac,sbc)){
		cout<<fa<<fb<<fc<<fd;
		return 0;
	}
	else fc=1;
	if(func(sac,sbc)){
		cout<<fa<<fb<<fc<<fd;
		return 0;
	}
	else fd=1;
	cout<<fa<<fb<<fc<<fd;
	return 0;
}
