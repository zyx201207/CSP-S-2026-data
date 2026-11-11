#include<bits/stdc++.h>
using namespace std;
long long sum[500010],a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,now=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1];
		sum[i]+=a[i];
		while((a[i]*(i-now)-(sum[i]-sum[now]))>m && now<i) now++;
		ans=max(i-now,ans);
	}
	cout<<ans;
	return 0;
} 
