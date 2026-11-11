#include <bits/stdc++.h>
using namespace std;
int n,answer;
long long m;
long long a[500005];
long long sum[500005]={0};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum[i]=sum[i-1]+a[i];
		if(i==1){
			answer=1;
			continue;
		}
//		cout << sum[i] << " ";
		long long s;
		int l=1,r=i,ans=l;
		int mid;
		while(l<=r){
			mid=(l+r)/2;
			s=sum[i]-sum[mid-1];
			if((i-mid+1)*a[i]-s<=m){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		answer=max(answer,i-ans+1);
//		cout << s << " " << ans << " ";
	}
	cout << answer;
	return 0;
}

