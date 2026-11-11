#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool b1,b2,b3,b4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		b1=1;
		if(c2[1]==c4[1]&&c2[0]==c4[0]){
			b2=1;
			if(c2[2]=='A'&&c4[2]=='B'||c4[2]=='C'||c2[2]=='B'&&c4[2]=='A'||c4[2]=='C'||c2[2]=='C'&&c4[2]=='A'||c4[2]=='B'||c2[2]=='F'&&c4[2]=='D'||c2[2]=='D'&&c4[2]=='F'){
				b3=1;
				if(c2[2]=='F'&&c4[2]=='D'||c2[2]=='D'&&c4[2]=='F'||c2[2]=='C'&&c4[2]=='B'||c2[2]=='B'&&c4[2]=='C'||c2[2]=='B'&&c4[2]=='A'||c2[2]=='A'&&c4[2]=='B'){
					b4=1;
				}
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
