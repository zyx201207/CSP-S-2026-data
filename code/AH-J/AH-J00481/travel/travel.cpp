#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		a1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a2=1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					a3=1;
					if(abs(s1[2]-s2[2])==1){
						a4=1;
					}
				}
			}
			else if(s1[2]=='F'||s1[2]=='D'){
				if(s2[2]=='F'||s2[2]=='D'){
					a3=1;
					a4=1;
				}		
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
