#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+1,K=31;
ll n,m,ans,a[N];
bool chk(int x){
	int cnt=n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=K;j++){
			if(((a[i]>>j)&1)<((x>>j)&1)){
				cnt--;
				break;
			}
		}
	}
	return cnt>=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=K;i>=0;i--){
		ans+=(1<<i);
		if(!chk(ans)) ans-=(1<<i);
	}
	cout<<ans;
	return 0;
}
