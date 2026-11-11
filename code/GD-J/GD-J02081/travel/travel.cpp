#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=2e6+10,mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int C,T=1;
int cp,cq;
string sp,sq;
void mian(){
	cin>>cp>>sp>>cq>>sq;
	if(cp!=cq) return cout<<"0000",void();
	if(sp[0]!=sq[0]||sp[1]!=sq[1]) return cout<<"1000",void();
	int bp=sp[2]-'A',bq=sq[2]-'A';
	if((bp>2&&bq<3)||(bp<3&&bq>2)) return cout<<"1100",void();
	if(abs(bp-bq)==1) return cout<<"1111",void();
	cout<<"1110";
	return;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	cin>>C>>T;
	while(T--) mian();
	return 0;
}
