#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
string c1,s1,c2,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	int xa=s1[0]*10+s1[1];
	int xb=s2[0]*10+s2[1];
	char ya=s1[2],yb=s2[2];
	bool fg1=(c1==c2);
	bool fg2=(fg1&&(xa==xb));
	bool fg3=(fg2&&((ya<='C'&&yb<='C')||(ya>'C'&&yb>'C')));
	bool fg4=(fg3&&(abs(ya-yb)==1));
	cout<<fg1<<fg2<<fg3<<fg4<<endl;
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
} 
