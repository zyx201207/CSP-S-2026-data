#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt,ans;
ll m,a[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	cnt=1;
	for(int i=2,j=1;i<=n;i++){
		sum+=cnt*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[j];
			cnt--;
			j++;
		}
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
