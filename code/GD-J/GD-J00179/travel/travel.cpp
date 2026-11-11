#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	int b1=(int)((b[0]-'0')*10+(b[1]-'0'));
	char b2=b[2];
	int d1=(int)((d[0]-'0')*10+(d[1]-'0'));
	char d2=d[2];
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b1==d1) cout<<1;
	else cout<<0;
	if(a==c&&b1==d1&&((b2<='C'&&d2<='C')||(b1>='D'&&d2>='D'))) cout<<1;
	else cout<<0;
	if(a==c&&b1==d1&&((b2<='C'&&d2<='C')||(b1>='D'&&d2>='D'))&&(b2-d2==1||d2-b2==1)) cout<<1;
	else cout<<0;
	return 0;
} 
