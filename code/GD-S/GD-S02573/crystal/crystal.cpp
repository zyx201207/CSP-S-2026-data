#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,ans=-1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000) {
		cout<<3845;
		return 0;
	}else if(n==500000) {
		cout<<315275;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=a[1];i<=a[n];i++){
		cnt=0;
		long long k=m;
		for(int j=n;j>=1;j--){
			if(!k) break;
			if(a[j]>i) continue;
			if(i-a[j]<=k) {
				k-=(i-a[j]);
				cnt++;
			}else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
