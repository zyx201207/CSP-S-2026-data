#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int aa,bb,cc,dd;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		aa=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			bb=1;
			if((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C')){
				cc=1;
				if(abs(b[2]-d[2])==1)dd=1;
			}
		}
	}
	cout<<aa<<bb<<cc<<dd;
}
