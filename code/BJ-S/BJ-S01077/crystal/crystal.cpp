#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		if(i<=ans) break;
		long long sum=0,cnt=1;
		for(long long j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m) break;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
