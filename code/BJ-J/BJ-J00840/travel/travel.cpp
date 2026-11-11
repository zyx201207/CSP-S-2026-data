#include<bits/stdc++.h>
using namespace std;
int c1,c2,r1,r2,q1,q2;
string s1,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1==c2);
	for(char i:s1){
		if(i>='0'&&i<='9'){
			r1*=10;r1+=(i-'0');
		} else {
			q1=(i-'A')+1;
		}
	}
	for(char i:s2){
		if(i>='0'&&i<='9'){
			r2*=10;r2+=(i-'0');
		} else {
			q2=(i-'A')+1;
		}
	}
    if(a){
		b=(r1==r2);
		if(b){
			c=((q1>=4&&q2>=4)||(q1<4&&q2<4));
			if(c){
				d=(abs(q1-q2)==1);
			}
		}
	}
	cout<<a<<b<<c<<d;
    return 0;
}
