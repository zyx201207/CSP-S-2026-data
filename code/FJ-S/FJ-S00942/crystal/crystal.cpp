#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long l=0,r=1;
		for(long long j=1;j<=n;j++){
			if(a[j]-a[i]>=0){
				b[j]=a[j]-a[i];
				l+=b[j];
				r++;
			}
			if(l>m)break;
		}
		if(l<=m){
			ans=max(ans,r);
		}
	}
	if(ans>n)cout<<n;
	else cout<<ans;
	return 0;
}
