#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')){
				cout<<1;
				if((int)s1[2]-(int)s2[2]==1 || (int)s1[2]-(int)s2[2]==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
//  Xterfushion,the best music in Arcaea
//  X X XXX
//	x x xxx
//	XX X XXX
//	xx x xxx
//	X X X XXXX
//	x x x xxxx
//	XX XX XXX X X
//	xx xx xxx x x
//	XXX
//	xxx
//	XXX X
//	xxx x
//	XXX XXX
//	xxx xxx
//	X X X X X X
//	x x x x x x
//	XXX X X
//	xxx x x
//	XXXXXX
//	xxxxxx
//	XX
//	xx
//	XX
//	xx
//	XX
//	xx
//	XX
//	xx
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	X
//	x
//	wo de Yin yue shui Jing bao zha le!!!!!!!!!!!!!!!!
	return 0;
} 
