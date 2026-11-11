#include <bits/stdc++.h>
#define ll long long
using namespace std;//freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
const int N=2e5+10;
ll n,m,a[N],ans,sl;
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=29;k>=0;k--){ sl=0;
		for(int i=1;i<=n;i++){
			if(f[i]) continue;
			if(a[i]&(1<<k)){
				++sl;
			}
		}
		if(sl<m) continue;
		ans+=(1<<k);
		for(int i=1;i<=n;i++){
			if(!(a[i]&(1<<k))) f[i]=1;
		}
	}cout<<ans;
	return 0;
}
/*
´óÑùÀý pass 
*/
