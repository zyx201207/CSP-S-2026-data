#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,s1,s2,m1,m2,n1,n2;
	cin>>r1>>r2>>s1>>s2;
	if(r1==s1){
		m1=r2[0]+r2[1];
		m2=s2[0]+s2[1];
		if(m1==m2){
			if(r2[2]=='D'&&s2[2]=='F'||r2[2]=='F'&&s2[2]=='D'||r2[2]=='A'&&s2[2]=='B'||r2[2]=='B'&&s2[2]=='A'||r2[2]=='A'&&s2[2]=='C'||r2[2]=='C'&&s2[2]=='A'||r2[2]=='B'&&s2[2]=='C'||r2[2]=='C'&&s2[2]=='B'){
				if(r2[2]=='D'&&s2[2]=='F'||r2[2]=='F'&&s2[2]=='D'||r2[2]=='A'&&s2[2]=='B'||r2[2]=='B'&&s2[2]=='A'||r2[2]=='B'&&s2[2]=='C'||r2[2]=='C'&&s2[2]=='B'){
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
	fclose(stdin);
	fclose(stdout);
} 
