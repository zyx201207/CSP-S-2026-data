#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			b=1;
			long long x=int(s1[2]),y=int(s2[2]);
			if(x<y){
				int t=x;
				x=y;
				y=t;
			}
			if(x-y>1 || (s1[2]=='D' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='D')){
				if((s1[2]=='A' && s2[2]=='C') || (s2[2]=='A' && s1[2]=='C')){
					c=1;
					d=0;
				}
				else{
					c=0;
					d=0;
				}
			}
			else{
				c=1;
				if((s1[2]=='A' && s2[2]=='C') || (s2[2]=='A' && s1[2]=='C'))  d=0;
				else d=1;
			}
		}
		else{
			b=0;
			c=0;
			d=0;
		}
	}
	else{
		a=0;
		b=0;
		c=0;
		d=0;
	}
	cout<<a<<b<<c<<d<<'\n';
	return 0;
}
