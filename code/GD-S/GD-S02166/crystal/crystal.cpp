#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans;
bool check(int x){
	int t=0,cnt=0;
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=n;i>=1;i--)
		if(b[i]<x&&m-t>=x-b[i]) t+=x-b[i],b[i]=x;
	for(int i=1;i<=n;i++) if(b[i]==x) cnt++;
	if(cnt>=ans){
		ans=cnt;
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=a[n];i++) check(i);
	cout<<ans;
	return 0;
}
