#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,c,d;
char a,b;
int n1,n2,n3,n4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n1=n2=n3=n4=0;
	cin>>c1>>c2>>c3>>c4;
	a=c2[2];
	b=c4[2];
	c=c2[0]+c2[1];
	d=c4[0]+c4[1];
	if(c1==c3) {
		n1=1;
		if(c==d) {
			n2=1;
			if((a>='A' and a<='C' and b>='A' and b<='C') or (a>='D' and b>='D' and a<='F' and b<='F')){
				n3=1;
				if((a+1==b) or(b+1)==a) n4=1;
			}
		}
	}
	cout<<n1<<n2<<n3<<n4;
	return 0;
}
