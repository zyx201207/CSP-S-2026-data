#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,c=0,d=0;
	string p1,p2;
	char z1,z2;
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	z1=s1[2];
	z2=s2[2];
    if(c1==c2){
        if(p1==p2){
            if(z1<='C'&&z2<='C'||z1>='D'&&z2>='D'){
                if(z1-z2==1||z2-z1==1){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
	return 0;
}
