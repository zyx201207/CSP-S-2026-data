#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010;
ll c,Q,n,m,a[N],ans;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
ll f(ll x,ll y){
	
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>Q;
	while(Q--){
		cin>>n>>m;
		for(ll i=1;i<=n;i++)a[i]=read();
		ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(f(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
