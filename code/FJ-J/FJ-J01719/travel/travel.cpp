#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool m=0,n=0,x=0,y=0;
long long cntb=0,cntd;
bool b1=1,d1=1;
string l={'A','B','C'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		m=1;
	}
	for(long long i=1;i<=2;i++){
		cntb+=b[i-1];
		cntd+=d[i-1];
	}
	if(m==1 && cntb==cntd){
		n=1;
	}
	for(int i=1;i<=3;i++){
		if(b[2]==l[i-1]){
			b1=0;
		}
		if(d[2]==l[i-1]){
			d1=0;
		}
	}
	if(n==1 && b1==d1){
		x=1;
	}
	if(x==1 && abs(b[2]-d[2])==1) y=1;
	cout<<m<<n<<x<<y;
	return 0;
}
