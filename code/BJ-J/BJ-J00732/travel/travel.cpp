#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool c1,c2,c3,c4;
	c1=a==c;
	c2=c1&&b[0]==d[0]&&b[1]==d[1];
	c3=c2&&(d[2]<='C')==(b[2]<='C');
	c4=c3&&max(d[2],b[2])-min(d[2],b[2])<=1;
	cout<<c1<<c2<<c3<<c4;
	return 0;
}
