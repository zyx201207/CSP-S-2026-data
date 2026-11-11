#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],aa=0;
bool check(long long p,long long x){
	long long cnt=0;
	for(int i=p;i<=x;i++){
		cnt+=(a[x]-a[i]);
	}
	return cnt<=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5005){
		for(int i=1;i<=n;i++){	
			long long l=i,r=n,ans=0;
			while(l<=r){
				long long mid=l+((r-l)/2);
				if(check(i,mid)){
					ans=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			ans-=i-1;
			aa=max(aa,ans);
		}cout<<aa<<'\n';
	}
	else{
		long long l=1,r=n,ans=0;
		while(l<=r){
			long long mid=l+((r-l)/2);
			if(check(1,mid)){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
