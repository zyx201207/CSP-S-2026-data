#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],pre[200005],suf[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20){
		int ans=0;
		for(int i=1;i<(1<<n);i++){
			int cnt=0,sum=INT_MAX;
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1))cnt++,sum&=a[j];
			}
			if(cnt!=m)continue;
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=LLONG_MAX;
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n<=2000&&m==2){
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=0;
		pre[0]=LLONG_MAX,suf[n+1]=LLONG_MAX;
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]&a[i];
		for(int i=n;i>=1;i--)
			suf[i]=suf[i+1]&a[i];
		for(int i=1;i<=n;i++)
			ans=max(ans,pre[i-1]&suf[i+1]);
		cout<<ans;
		return 0;
	}
	int cnt=-1;
	for(int i=0;i<=30;i++)
		if((1<<i)==n){
			cnt=i;
			break;
		}
	if(cnt!=-1){
		int ans=0;
		for(int i=1;i<=m;i++)
			ans+=(n>>i-1);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=LLONG_MAX;
	for(int i=1;i<=m;i++)
		ans&=a[i];
	cout<<ans;
	return 0;
}
