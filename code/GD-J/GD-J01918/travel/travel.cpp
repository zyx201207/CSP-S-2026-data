#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb,ans;
int fl1,fl2,fl3,fl4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		fl1=1;
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			fl2=1;
			char x=sa[2],y=sb[2];
			if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
				fl3=1;
				if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||
				(y=='A'&&x=='B')||(y=='B'&&x=='C')||(y=='D'&&x=='F')){
					fl4=1;
				}
			}
		}
	}
	ans+=fl1+'0';
	ans+=fl2+'0';
	ans+=fl3+'0';
	ans+=fl4+'0';
	cout<<ans;
	return 0;
}

