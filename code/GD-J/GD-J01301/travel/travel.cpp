#include<bits/stdc++.h>
using namespace std;
char a1,a2,aa,b1,b2,bb;
string A,B;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>A>>a1>>a2>>aa>>B>>b1>>b2>>bb; 
	if(A==B) {
		if((a1==b1)&&(a2==b2)){
			if(((aa=='A'||aa=='B'||aa=='C')&&(bb=='A'||bb=='B'||bb=='C')) || (aa=='D'||aa=='F')&&(bb=='D'||bb=='F')){
				if(aa-bb==1||bb-aa==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}
	else cout<<"0000";

	return 0;
}
