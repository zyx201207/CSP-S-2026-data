#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using arr=array<ll,2>;
const ll N=1e6+10;
void solve(){
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	string s="";
	if(c1==c3){
		s+='1';
		ll cnt=0;
		for(ll i=0;i<2;i++){
			if(c2[i]==c4[i]){
				cnt++;
			}
		}
		if(cnt==2){
			s+='1';
			if(c2[2]=='D'&&c4[2]=='F'||
			c2[2]=='F'&&c4[2]=='D'||
			c2[2]=='A'&&(c4[2]=='B'||c4[2]=='C')||
			c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C')||
			c2[2]=='C'&&(c4[2]=='A'||c4[2]=='B')){
				s+='1';
				if(c2[2]=='D'&&c4[2]=='F'||
				c2[2]=='F'&&c4[2]=='D'||
				c2[2]=='A'&&(c4[2]=='B')||
				c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C')||
				c2[2]=='C'&&(c4[2]=='B')){
					s+='1';
				}else{
					s+='0';
				}
			}else{
				s+="00";
			}
		}else{
			s+="000";
		}
	}else{
		s="0000";
	}
	cout<< s << "\n";
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ll t;cin>>t;while(t--)
	solve();
	return 0;
}
