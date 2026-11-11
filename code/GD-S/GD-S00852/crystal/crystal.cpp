#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006],sum[500005],cnt[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
		cnt[i]=cnt[i-1]+sum[i]*(i-1);
	}
	for(int i=2;i<=n;i++){
		if(cnt[i]>m){
			ans=i-1;
			break;
		}
	}
	cout<<ans;
	return 0;
} 
