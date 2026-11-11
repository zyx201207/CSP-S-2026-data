#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],sum[500009],ans=1,f=0,zheng,fu,ling,da=0,shangzhi,zhi;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			zhi+=a[i]-a[j];
			if(zhi<=m){
				da++;
			}
			else{
				break;
			}
		}
		cout<<zhi<<endl;
		ans=max(ans,da);
		if(ans==315275){
			cout<<i<<endl;
		}
		zhi=0;
		da=0;
	}
	cout<<ans+1;
	return 0;
}