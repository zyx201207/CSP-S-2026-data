#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		c1++;
	if(b[1]==d[1]){
		c2++;
		if((b[2]>='A' and b[2]<='C' and d[2]>='A' and d[2]<='C') or (b[2]>='D' and b[2]<='F' and d[2]>='D' and d[2]<='F')){
			c3++;
		}
	}
		if(b[2]-d[2]==1 or d[2]-b[2]==1){
					c4++;
				}
			if ((b[2]=='C' and d[2]=='D' or d[2]=='C' and b[2]=='D') or (b[1]!=d[1])){
				c4--;
			}
	}
	cout<<c1<<c2<<c3<<c4;
	return 0;
}
