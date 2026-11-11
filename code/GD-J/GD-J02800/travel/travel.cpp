#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int n1,n2,n3,n4;
int main(){
	freopen("travel.txt","r",stdin);
	freopen("travel.txt","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		n1=0;
		n2=0;
		n3=0;
		n4=0;
	}
	else{
		n1=1;
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			n2=1;
	if(((s2[2]=='D'||s2[2]=='F')&&(c2[2]=='D'||c2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'))){
				n3=1;
				if(s2[2]+1==c2[2]||s2[2]-1==c2[2]||(s2[2]=='D'&&c2[2]=='F')||(c2[2]=='D'&&s2[2]=='F')){
					n4=1;
				}
				else{
					n4=0;
				}
			}
			else{
				n3=0;
				n4=0;
			}
		}
		else{
			n2=0;
			n3=0;
			n4=0;
		}
	}
	cout<<n1<<n2<<n3<<n4;
	return 0;
}
