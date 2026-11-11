#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long cnt=0,f=1;
		for(int j=i-1;j>=1;j--){
			f++;
			cnt+=a[i]-a[j];
			if(cnt<=m) ans=max(ans,f);
			else break;
		}
	}
	cout<<ans;
	return 0;
}