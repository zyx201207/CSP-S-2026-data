#include<bits/stdc++.h>
using namespace std;
long long a[50000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ma=0,mi=1e9,sum,cnt=0,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) {
		cin>>a[i]; 
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}	
	sort(a+1,a+n+1);
	for(long long i=mi;i<=ma;i++){
		sum=0;
		cnt=0;
		for(long long j=1;j<=n;j++){
			if(i<a[j]){
				break;
			}
			sum+=i-a[j];
			if(sum>m){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
