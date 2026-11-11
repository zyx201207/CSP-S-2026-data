#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long dif[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	if(a[n]<=20){
		long long ans=0;
		for(long long t=a[n]+m;t>=a[1];t--){
			long long m1=m,now=0;
			for(int i=1;i<=n;i++){
				if(a[i]>t) continue;
				if(m1>=t-a[i]){
					m1-=(t-a[i]);
					now++;
				}
			}
			ans=max(ans,now);
		}
		cout<<ans<<endl;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
		dif[i]=dif[i-1]+(i-1)*(a[i]-a[i-1]);
	
	int ans=upper_bound(dif+1,dif+n+1,m)-dif-1;
	cout<<ans<<endl;
	return 0;
}
