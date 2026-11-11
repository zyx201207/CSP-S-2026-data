#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		if(c[0]==d[0] && c[1]==d[1]) {
			cout<<1;
			if((c[2]=='A'^c[2]=='B'^c[2]=='C') &&(d[2]=='A'^d[2]=='B'^d[2]=='C')){
				cout<<1;
				if(abs(c[2]-d[2])==1) cout<<1;
				else cout<<0;
			}
			else if((c[2]=='D'^c[2]=='F')&&(d[2]=='D'^d[2]=='F')) cout<<1;
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
