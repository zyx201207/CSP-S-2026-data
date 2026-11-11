#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long k=m,cnt=0;
			for(int j=i;j>=1;j--){
				if(a[i]-a[j]<=k){
					k-=a[i]-a[j];
					cnt++;
				}
				else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
		printf("%lld\n",ans);
	}
	else{
		long long k=m,cnt=0;
		for(int j=n;j>=1;j--){
			if(a[n]-a[j]<=k){
				k-=a[n]-a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
} 
