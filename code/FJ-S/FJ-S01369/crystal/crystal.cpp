#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010];
long long ans=0,cnt,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum=m;
		cnt=0;
		for(long long j=i;j>=1;j--){
			if(sum>=a[i]-a[j]){
				sum-=a[i]-a[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
