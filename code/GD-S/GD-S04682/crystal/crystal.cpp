#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	sort(a+1,a+1+n);
	for(long long i=n;i>=1;i--){
		long long  m1=m,cnt=0;
		for(long long j=i;j>=1;j--){
			if(m1>=a[i]-a[j]){
				cnt++;
				m1-=(a[i]-a[j]);
			}
		}
		ans=max(ans,cnt);
	} 
	cout<<ans;
	return 0;
}
