#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans;
bool cmp(long long a, long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if (n<=5000){
		for (int i=1;i<=n;i++){
			long long an=1, lm=m;
			for (int j=i+1;j<=n;j++){
				if (a[i]-a[j]<=lm){
					lm-=a[i]-a[j];
					an++;
				}
			}
			ans=max(ans,an); 
		}
	}
	else{
		long long sum=0;
		for (int i=2;i<=n;i++) sum+=a[1]-a[i];
		if (sum<=m) ans=n;
		else{
			for (int i=2;i<=n;i++){
				if (a[1]-a[i]<=m){
					m-=a[1]-a[i];
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
