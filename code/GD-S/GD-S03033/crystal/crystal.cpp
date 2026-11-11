#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long sum=0,cnt=0;
		for(int j=i-1;j>=1;j--){
			if(sum+(a[i]-a[j])>m)break;
			sum+=a[i]-a[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans+1;
	return 0;
}
