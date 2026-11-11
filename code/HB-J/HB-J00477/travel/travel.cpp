#include<bits/stdc++.h>
using namespace std;
char a1[5],a2[5],s1[3],s2[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>s1>>a2>>s2;
    int z1=0,z2=0;
    for(int i=0;i<2;i++){
		z1*=10;
		z1+=(a1[i]-48);
	}
	for(int i=0;i<2;i++){
		z2*=10;
		z2+=(a2[i]-48);
	}
	if(z1==z2){
		int z3=0,z4=0;
		for(int i=0;i<2;i++){
			z3*=10;
			z3+=(s1[i]-48);
		}
		for(int i=0;i<2;i++){
			z4*=10;
			z4+=(s2[i]-48);
		}
		if(z3==z4){
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				if(abs(int(s1[2])-int(s2[2]))==1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
