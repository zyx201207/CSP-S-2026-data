#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,zifu;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				if(s1[2]=='B'||s2[2]=='B'){
					zifu="1111";
				}
				else{
					zifu="1110";
				}
			}
			else{
				if(s1[2]=='D'&&s2[2]<='F'&&s2[2]>='D'&&s1[2]<='F'){
					zifu="1111";
				}
				else{
					zifu="1100";
				}
			}
		}
		else{
			zifu="1000";
		}
	}
	else{
		zifu="0000";
	}
	cout<<zifu;
	return 0;
}
