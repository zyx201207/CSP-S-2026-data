#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b==d) cout<<1;
	else cout<<0;
	if(a==c&&b==d&&!(x<='C'&&y>'C')&&!(x>'C'&&y<='C')) cout<<1;
	else cout<<0;
	if(a==c&&b==d&&!(x<='C'&&y>'C')&&!(x>'C'&&y<='C')&&(y==x+1||x==y+1||(x=='D'&&y=='F')||(x=='F'&&y=='D'))) cout<<1;
	else cout<<0;
	return 0;
}
