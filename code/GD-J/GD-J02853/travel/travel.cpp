#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1]){
		
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			
			if((a2[2]-'A'<=2&&b2[2]-'A'<=2)||(a2[2]-'A'>2&&b2[2]-'A'>2)){
				
				if(abs((a2[2]-'A')-(a2[2]-'A'))==1){
					cout<<1111;
				}
				else cout<<1110;
			}
			else cout<<1100;
		}
		else cout<<1000;
	} 
	else cout<<0000;
	return 0;
}

