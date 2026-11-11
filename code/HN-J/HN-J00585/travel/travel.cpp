#include<bits/stdc++.h>
using namespace std;
const int N=+5;
int c1,d1;
string c2,d2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>c2>>d1>>d2;
	if(c1==d1) a=1;
	if(c2[0]==d2[0]&&c2[1]==d2[1]&&a==1) b=1;
	if(c2[2]<='C'&&c2[2]>='A'&&d2[2]<='C'&&d2[2]>='A'&&b==1||c2[2]=='F'&&d2[2]=='D'&&b==1||c2[2]=='D'&&d2[2]=='F'&&b==1) c=1;
	int s=c2[2],y=d2[2];
	if(max(s,y)-min(s,y)==1&&c==1){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
/*





llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll








*/
