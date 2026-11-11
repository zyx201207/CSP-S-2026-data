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
int res=0,n,a[N],m;
void mian(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int S=30;~S;S--){
		int tmp=res|(1<<S),cnt=0;
		for(int i=1;i<=n;i++) 
			cnt+=((a[i]&tmp)==tmp);
		if(cnt>=m) res=tmp;
	}
	cout<<res;
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	cin>>C>>T;
	while(T--) mian();
	return 0;
}

