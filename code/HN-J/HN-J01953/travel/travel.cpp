#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s11,s12,s13,s14;
	cin>>s11>>s12>>s13>>s14;
	int a=0,b=0,c=0,d=0;
	char c110=s11[0];
	char c111=s11[1];
	char c120=s12[0];
	char c121=s12[1];
	char c122=s12[2];
	char c130=s13[0];
	char c131=s13[1];
	char c140=s14[0];
	char c141=s14[1];
	char c142=s14[2];
	if(c110==c130 && c111==c131){
		a=1;
		if(c120==c140 && c121==c141){
			b=1;
			if((c122<=67 && c142<=67)||(c122>67 && c142>67)){
				c=1;
				if(abs(c122-c142)==1 && c122+c142!=67+68)d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
