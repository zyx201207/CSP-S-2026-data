#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	else{
		cout<<1;
		if(b[0]!=d[0]||b[1]!=d[1]){
			cout<<"000";
		}
		else{
			cout<<1;
			if(((b[2]>='A'&&b[2]<='C')&&(d[2]=='D'||d[2]=='F'))||((d[2]>='A'&&d[2]<='C')&&(b[2]=='D'||b[2]=='F'))){
				cout<<"00";
			}
			else{
				cout<<1;
				if(b[2]+1==d[2]||b[2]-1==d[2]||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}
