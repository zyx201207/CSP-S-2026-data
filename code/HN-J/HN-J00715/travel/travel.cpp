#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string w1,w2;
	char z1,z2;
	w1 = s1[0]+s1[1];
	w2 = s2[0]+s2[1];
	z1 = s1[2];
	z2 = s2[2];
	if(c1==c2){
		cout<<1;
		if(w1==w2){
			cout<<1;
			if((z1=='D' && z2=='F' )||(z1=='F' &&z2=='D') ||(z1!='D' && z1!='F' &&z2!='D' && z2!='F')){
				cout<<1;
				if(z1+1==z2 || z1-1==z2){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}	
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	


	return 0;
} 
