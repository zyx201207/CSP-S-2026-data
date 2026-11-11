#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int cnt=1,sum;
int ans=LLONG_MIN;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[n+1]=LLONG_MAX;
	sum=m;
	for(int i=1;i<=n-1;i++){
		sum-=(a[i+1]-a[i])*i;
		if(sum>=0){
			cnt++;
		}else{
			sum+=(a[i+1]-a[i])*i;
			while(a[i+1]==a[i]){
				cnt++;
				i++;
			}
			ans=max(ans,cnt);
			break;
		}
	}
	ans=max(ans,cnt);
	for(int i=1;i<=n-1;i++){
		cnt--;
		if(i+ans>n){
			break;
		}
		sum+=a[i+cnt]-a[i];
		while(sum-(a[i+cnt+1]-a[i+cnt])*cnt>=0&&i+cnt+1<=n){
			sum-=(a[i+cnt+1]-a[i+cnt])*cnt;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
