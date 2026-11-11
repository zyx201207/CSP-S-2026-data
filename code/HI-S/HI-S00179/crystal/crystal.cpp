#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool f=1;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			f=0;
		}
	}
	if(f){
		long long ans=0;
		long long gc=a[2]-a[1];
		for(int i=0;i<=n;i++){
			if(m-i*gc>=0){
				m=m-i*gc;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++){
		long long ans=1;
		long long mm=m;
		for(int j=i-1;j>=1;j--){
			if(mm>=a[i]-a[j]){
				ans++;
				mm=mm-(a[i]-a[j]);
			}
		} 
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
