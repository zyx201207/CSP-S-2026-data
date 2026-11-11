#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	string x,l,y,r;cin>>x>>l>>y>>r;
	if((x[0]-'0')*10+(x[1]-'0')!=(y[0]-'0')*10+(y[1]-'0')){
		cout<<"0000";return 0;
	}
	cout<<1;
	if((l[0]-'0')*10+(l[1]-'0')!=(r[0]-'0')*10+(r[1]-'0')){
		cout<<"000";return 0;
	}
	cout<<1;
	if(l[2]=='F'||l[2]=='D'){
		if(r[2]!='F'&&r[2]!='D'){
			cout<<"00";return 0;
		}
	}
	if(l[2]=='A'||l[2]=='B'||l[2]=='C'){
		if(r[2]!='A'&&r[2]!='B'&&r[2]!='C'){
			cout<<"00";return 0;
		}
	}
	cout<<1;
	int xx=l[2],yy=r[2];
	if(abs(xx-yy)==1)cout<<'1';
	else cout<<0;
} 
