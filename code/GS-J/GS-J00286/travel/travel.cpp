#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>a2>>b1>>b2;
	int x,y,z,q;
	if(a1==b1){
		x=1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			y=1;
			if(a2[2]=='A'&&b2[2]=='B'||a2[2]=='B'&&b2[2]=='A'||a2[2]=='B'&&b2[2]=='C'||a2[2]=='C'&&b2[2]=='B'||a2[2]=='A'&&b2[2]=='C'||a2[2]=='C'&&b2[2]=='A'||a2[2]=='D'&&b2[2]=='F'||a2[2]=='F'&&b2[2]=='D'){
				z=1;
				if(a2[2]=='A'&&b2[2]=='C'||a2[2]=='C'&&b2[2]=='A'){
					q=0;
				}else{
					q=1;
				}
			}else{
				z=0;
				q=0;
			}
		}else{
			y=0;
			z=0;
			q=0;
		}
	}else{
		x=0;
		y=0;
		z=0;
		q=0;
	}
	cout<<x<<y<<z<<q;
	return 0;
}
