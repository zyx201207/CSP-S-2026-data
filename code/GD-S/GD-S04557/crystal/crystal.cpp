#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		b[i]=a[n-1]-a[i];
	}
	long long ans=0;
	for(long long i=n-1;i>=0;i--){
		long long cnt=0,ant=0;
		for(long long j=i;j>=0;j--){
			
			cnt+=b[j]-b[i];
			if(cnt>m)break;
			ant++;
	//		cout<<a[j]<<' ';
		}
	//	cout<<endl;
		ans=max(ans,ant);
		if(ans>=i)break;
	}
	cout<<ans<<'\n';
} 
