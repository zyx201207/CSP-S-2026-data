#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],b[N],f[N],sum,js,t,k,ans=1,L,R,M;
bool check(long long pos,long long i){
	if((a[i]*(i-pos+1)-b[i]+b[pos-1])>m)
		return 1;
	else
		return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
//		sum+=a[i];
//		if((a[i]*i-sum)<=m)
//			ans=i;
		L=0,R=i+1;
		while(L<=R){
			M=(L+R)>>1;
			if(check(M,i))
				L=M+1;
			else
				R=M-1;
		}
		ans=max(ans,i-M+1);
	}
	cout<<ans;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal2.in","r",stdin);
//	freopen("crystal2.out","w",stdout);
//	freopen("crystal3.in","r",stdin);
//	freopen("crystal3.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
