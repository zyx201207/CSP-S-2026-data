#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long k=m;
		//cout<<i<<" ";
		for(int j=i-1;j>=1;j--){
			if(k>=a[i]-a[j]){
				//cout<<k<<" ";
				k=k-a[i]+a[j];
				ans++;
			}
		}
		long long j=i+1;
		while(a[i]==a[j]){
			//cout<<1<<" ";
			ans++;
			j++;
		}
		//cout<<ans<<endl;
		maxx=max(maxx,ans);
		ans=1;
	}
	printf("%lld",maxx);
	return 0;
}
