#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("teavel.in","r",stdin);
    freopen("teavel.out","w",stdout);
    string c1,c2;
    char s1,s2,s3,s4,s5,s6;
    cin>>c1>>s1>>s2>>s3>>c2>>s4>>s5>>s6;
    if(c1!=c2){
		cout<<"0000";
		return 0;
		}
		if(c1==c2){
			if(s1!=s4||s2!=s5){
				cout<<"1000";
				return 0;
				}
			if(s1==s4&&s2==s5){
				if((int(s3)+1==int(s6)||int(s3)-1==int(s6))&&(s3=='A'&&s6=='F')){
					cout<<"1110";
					}
				if(int(s3)+1==int(s6)||int(s3)-1==int(s6)){
					cout<<"1111";
					return 0;
					}
				//else cout<<"1110"
				}
			}
    return 0;}
