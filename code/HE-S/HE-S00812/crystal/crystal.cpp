#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,a[500010],sum[500010];
bool check(long long st,long long x){
	long long cost=sum[st]-sum[x-1],p=a[st]*(st-x+1);
	return (p-cost)<=m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=2;i<=n;i++){
		long long l=0,r=i-1,ansn=i-1;
		while (l<=r){
			long long mid=(l+r)>>1;
			if (check(i,mid)){
				ansn=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-ansn+1);
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
