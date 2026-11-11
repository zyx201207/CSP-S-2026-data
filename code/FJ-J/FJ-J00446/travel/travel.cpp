#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool b1=0,b2=0,b3=0,b4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		b1=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			b2=1;
			int seat1=s1[2]-'A'+1,seat2=s2[2]-'A'+1;
			if(seat1<=3 && seat2<=3){
				b3=1;
				if(abs(seat1-seat2)<=1){
					b4=1;
				}
			}
			if(seat1>=4 && seat2>=4){
				b3=1;
				b4=1;
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
