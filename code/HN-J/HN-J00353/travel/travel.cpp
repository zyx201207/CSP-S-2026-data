#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int s1,s2,s3,s4;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) s2=1,cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&s2==1) s3=1,cout<<1;
	else cout<<0;
	if((b[2]<='C')==(d[2]<='C')&&s2==1&&s3==1) s1=1,cout<<1;
	else cout<<0;
	if(s1==0||s2==0||s3==0) cout<<0;
	else if(b[2]+1==d[2]||d[2]+1==b[2]) cout<<1;
	else cout<<0;
	return 0;
}
