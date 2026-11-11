#include<bits/stdc++.h>
using namespace std;
const int N=100100;
string s="0000";
string c1,c2,s1,s2;
string cc,ss;
char fa,fb;
int n,m,k,l;
int iest(char d){
	if(d=='A'||d=='B'||d=='C') return 1;
	else return 2;
}
bool check1(){return c1==c2;}
bool check2(){return cc==ss;}
bool check3(){return iest(fa)==iest(fb);}
bool check4(){return max(fa-fb,fb-fa)==1;}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cc=s1.substr(0,2);
	ss=s2.substr(0,2);
	fa=s1[2],fb=s2[2];
	bool r1,r2,r3,r4;
	r1=check1(),r2=check2(),r3=check3(),r4=check4();
	cout<<(r1?1:0)<<(r1&&r2?1:0);
	cout<<(r1&&r2&&r3?1:0)<<(r1&&r2&&r3&&r4?1:0);
	return 0;
}

