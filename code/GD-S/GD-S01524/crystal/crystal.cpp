#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1,0),pre(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]+a[i-1];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			if(a[i]*(i-j+1)-(pre[i]-pre[j-1])<=m){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
}

