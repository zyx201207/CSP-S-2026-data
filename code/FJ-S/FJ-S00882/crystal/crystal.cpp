#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long sum=0;
long long ans=INT_MIN;
long long cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		sum=0;
		cnt=1;
		for(long long j=1;j<i;j++){
			sum+=a[i]-a[j];
			if(sum<=m){
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
