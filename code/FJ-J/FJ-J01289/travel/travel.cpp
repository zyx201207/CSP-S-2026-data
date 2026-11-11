#include<bits/stdc++.h>
#define int long long
using namespace std; 
struct P{string a,b;}r,x;
signed main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>r.a>>r.b>>x.a>>x.b;
	if(r.a==x.a){
		cout<<1;
		if(r.b[0]==x.b[0]&&r.b[1]==x.b[1]){
			cout<<1;
			if(r.b[2]>='D'&&x.b[2]>='D'){
				cout<<11;
			}
			else if(r.b[2]<='C'&&x.b[2]<='C'){
				cout<<1;
				if(r.b[2]=='B'||x.b[2]=='B')cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
