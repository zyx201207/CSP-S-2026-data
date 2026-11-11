#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=5e5+7;
typedef long long ll;
ll m,a[N],pre[N],cha;
int n,ans;
void solve1(){ 
	sort(a+1,a+n+1);
	int ans=1,sum=1;
	for(int i=n-1;i>=1;i--) {
		if(a[i]!=a[i+1]) {
			ans=max(ans,sum);
			sum=1;
			continue;
		}
		sum++;
	}
	ans=max(ans,sum);
	cout<<ans;
	return ;
}
int main(){ 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1) {
		cout<<1;
		return 0;
	}
	if(m==0) {
		solve1();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--) {
		pre[i]=pre[i+1]+a[n]-a[i];
	}
//	for(int i=1;i<=n;i++) cout<<pre[i]<<' ';
	int end=n;
	for(int i=n,j=1;i>=1;i--,j++) {
		if(pre[i]<=m) continue;
//	cout<<ans<<' ';
		ans=max(ans,j);
		break;
	}
	while(end>ans) {
		for(int i=end-1;i>=1;i--) {
//			cout<<a[end]<<' '<<a[i]<<"  ";
			if(a[i]!=a[end]) {
				cha=a[end] - a[i];
				end = i;
				break;
			}
		}
		
		for(int i=end,j=1;i>=1;i--,j++) {
			pre[i]-=cha*j;
		}
//		for(int i=1;i<=end;i++) cout<<pre[i]<<' ';
//		cout<<'\n';
		bool ok=true;
		for(int i=end;i>=1;i--) {
			if(pre[i]<=m) continue;
//			cout<<ans<<' ';
			ans=max(ans,end-i);
			ok=false;
			break;
		}
		if(ok) ans=max(ans,end);
	}
	cout<<ans;
	return 0;
}