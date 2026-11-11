#include<bits/stdc++.h>
using namespace std;
int n,m,p=0,ans=1;
long long a[500005],pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(p<i)p=i;
		while((p<n)&&(a[p+1]*(p-i+1)-(pre[p]-pre[i-1])<=m))p++;
		ans=max(ans,p-i+1);
	}
	cout<<ans;
	return 0;
}
