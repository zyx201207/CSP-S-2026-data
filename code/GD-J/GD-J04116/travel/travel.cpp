#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool aa,ab,ac,ad;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		aa=1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			ab=1;
			if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D')){
				ac=1;
				if(abs(a2[2]-'A'-(b2[2]-'A'))==1||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')){
					ad=1;
				}
			}
		}
	}
	cout<<aa<<ab<<ac<<ad;
	return 0;
} 
