#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],maxx[500005];
signed main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	int qjh=0,l=0;
	for(int i=1;i<=n;i++){
		qjh+=(i-l)*b[i];
		while(qjh>m&&l<i){
			qjh-=a[i]-a[l];
			l++;
		}
		maxx[i]=i-l+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,maxx[i]);
	cout<<ans;
	return 0;
}
