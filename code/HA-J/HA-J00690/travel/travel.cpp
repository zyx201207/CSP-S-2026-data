#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod=1e9+7;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string p="",q="";
	if(a==c) {
		cout<<1;
		p=b[0]+b[1],q=d[0]+d[1];
		if(p==q){
			cout<<1;
			if((b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='A'&&d[2]=='C')||(d[2]=='A'&&b[2]=='B'||d[2]=='B'&&b[2]=='C'||d[2]=='D'&&b[2]=='F'||d[2]=='A'&&b[2]=='C')){
				cout<<1;
				if((b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F')||(d[2]=='A'&&b[2]=='B'||d[2]=='B'&&b[2]=='C'||d[2]=='D'&&b[2]=='F')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
