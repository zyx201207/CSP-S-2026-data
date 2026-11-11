#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,c;
string b,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int b1=(b[0]-'0')*10+(b[1]-'0'),d1=(d[0]-'0')*10+(d[1]-'0');
	if(b1==d1) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int b2=b[2]-'0',d2=d[2]-'0';
	if(b2<=19&&d2<=19 || b2>=20&&d2>=20) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(b2==17&&d2==18 || b2==18&&d2==19 || b2==20&&d2==22) cout<<1;
	else cout<<"0";
	return 0;
} 
