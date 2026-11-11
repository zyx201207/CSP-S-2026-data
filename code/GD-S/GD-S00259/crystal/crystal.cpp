#include<bits/stdc++.h>
using namespace std;
long long a[500005],pre[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=1,l=1,r=1;
	while(r<=n){
		long long sum=a[r]*(r-l);
		if(sum-(pre[r-1]-pre[l-1])<=m){
			ans=max(r-l+1,ans);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
