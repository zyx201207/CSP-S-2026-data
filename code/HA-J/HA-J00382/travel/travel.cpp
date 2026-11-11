#include<bits/stdc++.h>
using namespace std;
int c1,c2,o1,o2,e;
string z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		o1=(z1[0]-'0')+(z1[1]'-0');
		o2=(z1[0]-'0')+(z1[1]'-0');
		if(o1!=02){
			cout<<"1000";
		}else{
			char q1,q2;
			q1=z1[2];
			q2=z2[2];
			if((q1=='A'||q1=='B'||q1=='C')&&(q2=='D'||q2=='F')){
				cout<<"1100";
			}else{
				e=abs((q1-'A')-(q2-'A'));
				if(e==1){
					cout<<"1111";
				}else{
					cout"1110";
				}
			}
			
		}
	}
	return 0;
}
