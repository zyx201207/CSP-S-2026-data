//GZ-J00686遵义市第十二中学刘彦城
#include<bits/stdc++.h>
using namespace std;
struct travel{
	string car;
	string seat;
}a[3];
int ce(char b){
	if(b=='A'||b=='B'||b=='C') return 1;
	if(b=='D'||b=='F') return 0;
}
bool side(char c,char d){
	if(c=='A'&&d=='B') return true;
	else if(c=='B'&&d=='A') return true;
	else if(c=='B'&&d=='C') return true;
	else if(c=='C'&&d=='B') return true;
	else if(c=='E'&&d=='F') return true;
	else if(c=='F'&&d=='E') return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int q=0,w=0,e=0,r=0;
	cin>>a[1].car>>a[1].seat>>a[2].car>>a[2].seat;
	if(a[1].car==a[2].car) q=1;
	else q=0;
	string rs;
	rs+=a[1].seat[0];
	rs+=a[1].seat[1];
	string xs;
	xs+=a[2].seat[0];
	xs+=a[2].seat[1];
	if(rs==xs&&q==1) w=1;
	else w=0;
	if((ce(a[1].seat[2])==ce(a[2].seat[2]))&&w==1) e=1;
	else e=0;
	char rh=a[1].seat[2];
	char xh=a[2].seat[2];
	if((side(rh,xh)==true)&&e==1) r=1;
	else r=0;
	cout<<q<<w<<e<<r;
	return 0;
} 
