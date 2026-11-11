#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,m;
int cnt[31];
bool bz[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=0;j<30;++j){
			if(((1ll<<j)&a[i])>0){
				cnt[j]++;
			}
		}
	}
	int ans=0;
	for(int i=29;i>=0;--i){
		if(cnt[i]<m)continue;
		for(int j=1;j<=n;++j){
			if(bz[j])continue;
			if(((1ll<<i)&a[j])==0){
				for(int k=29;k>=0;--k){
					if(((1ll<<k)&a[j])>0){
						cnt[k]--;
					}
				}
				bz[j]=1;
			}
		}
		ans+=(1ll<<i);
	}
	cout<<ans;
	return 0;
}
