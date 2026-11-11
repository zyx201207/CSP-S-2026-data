#include <bits/stdc++.h>

long long a[500001];

int main(){
	std::freopen("crystal.in","r",stdin);
	std::freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	int n,m;
	std::cin>>n>>m;
	for (int i=1;i<=n;i++) std::cin>>a[i];
	long long l=-1e18,r=1e18+1;
	while (l+1<r){
		long long mid=(l+r)>>1,cnt=0;
		bool flag=true;
		for (int i=1;i<=n;i++){
			cnt+=(mid-a[i])*(a[i]<mid);
			if (cnt>m){
				flag=false;
				break;
			}
		}
		if (flag) l=mid;
		else r=mid;
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=(a[i]<=l);
	std::cout<<ans<<std::endl;
	return 0;
}

