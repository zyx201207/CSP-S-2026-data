#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char s11,s22;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((s11=='A'||s11=='B'||s11=='C')&&(s22=='A'||s22=='B'||s22=='C')||(s11=='D'||s11=='F')&&(s22=='D'||s22=='F')){
				cout<<1;
				if(abs(s11-s22)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

