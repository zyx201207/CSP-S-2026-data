#include<bits/stdc++.h>
namespace KH{
using namespace std;
#define int long long
void solve(){
	int cr=0,cx=0,pr=0,px=0,lr,lx;
	string s;
	cin>>s;
	for(int i=0;i<2;i++) cr=cr*10+(s[i]-'0');
	cin>>s;
	for(int i=0;i<2;i++) pr=pr*10+(s[i]-'0');
	lr=(s[2]-'A')+1;
	cin>>s;
	for(int i=0;i<2;i++) cx=cx*10+(s[i]-'0');
	cin>>s;
	for(int i=0;i<2;i++) px=px*10+(s[i]-'0');
	lx=(s[2]-'A')+1;
	if(cr!=cx){cout<<"0000\n";return;}
	else if(pr!=px){cout<<"1000\n";return;}
	else if((lr<=3&&lx>3)||(lr>3&&lx<=3)){cout<<"1100\n";return;}
	else if(abs(lr-lx)>1){cout<<"1110\n";return;}
	else cout<<"1111\n";
}
void main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	while(T--){
		solve();
	}
}
#undef int
}
int main(){KH::main();}
