#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5201314;
string A,B,C,D;
//====================================================================
inline void Ans(bool type,ll len){
	if(type) cout<<1;
	else while(len){ cout<<'0'; --len; }
}
//====================================================================
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>A; cin>>B; cin>>C; cin>>D;
	if(A==C){ 
		Ans(1,520);
		if(B[0]==D[0]&&B[1]==D[1]){
			Ans(1,520);
			bool X=false,Y=false;
			if(B[2]>='A'&&B[2]<='C') X=true;
			if(D[2]>='A'&&D[2]<='C') Y=true;
			if(X==Y){
				Ans(1,520);
				ll a=(ll)(B[2]),b=(ll)(D[2]);
				if(max(a,b)-min(a,b)==1) Ans(1,520);
				else Ans(0,1);
			} else Ans(0,2);
		} else Ans(0,3);
	} else Ans(0,4);
	return 0;
} 
