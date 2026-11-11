#include<bits/stdc++.h>
using namespace std;
int c1,c2,setr,setx;
string sr,sx;
string ans="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c1>>sr>>c2>>sx;
	setr=(sr[0]-'0')*10+sr[1]-'0';
	setx=(sx[0]-'0')*10+sx[1]-'0';
	if(c1==c2){
		ans+='1';
		if(setr==setx){
			ans+='1';
			char r=sr[2],x=sx[2];
			if(r>=x){
				swap(r,x);
			}
			if((r>='A'&&r<='C'&&x>='A'&&x<='C')||(r>='D'&&r<='F'&&x>='D'&&x<='F')){
				ans+='1';
				if((r=='A'&&x=='B')||(r=='B'&&x=='C')||(r=='D'&&x=='F')){
					ans+='1';
				}else{
					ans+='0';
				}
			}else{
				ans+='0';
				ans+='0';
			}
		}else{
			ans+='0';
			ans+='0';
			ans+='0';
		}
	}
	else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
