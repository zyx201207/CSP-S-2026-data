//GZ-J00605，邱宣然，华东师范大学附属贵阳学校
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii int
#define bb bool
#define cc char
#define dd double
#define ss string
#define vv void
#define rr return
#define ve vector
#define in cin
#define ou cout
vv ai(){
	ll a,b,c,d;
	cc c1,c2;
	bb b1=0,b2=0,b3=0,b4=0;
	in>>a>>c>>c1>>b>>d>>c2;
	if(a==b){
		ou<<"1";
		if(c==d){
			ou<<"1";
			if((c1=='A'&&c2=='B')||(c1=='A'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='A')||(c1=='C'&&c2=='B')||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')){
				ou<<"1";
				if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')){
					ou<<"1";
				}else{
					ou<<"0";
				}
			}else{
				ou<<"00";
			}
		}else{
			ou<<"000";
		}
	}else{
		ou<<"0000";
	}
	rr;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll t=1;
	while(t--){
		ai();
	}
	rr 0;
} 
