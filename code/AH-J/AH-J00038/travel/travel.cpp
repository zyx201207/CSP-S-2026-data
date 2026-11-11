#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int a1,a2,a3,a4;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(b[2]=='F') b[2]='E';
    if(d[2]=='F') d[2]='E';
	if(a==c){
		a1=1;
		if(b[0]==d[0]&&b[1]==d[1]) {
			a2=1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')) {
				a3=1;
				if(b[2]+1==d[2]||b[2]-1==d[2]) a4=1;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
}
