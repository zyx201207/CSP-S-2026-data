#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],pre[1000010];
int check(int x){
	for(int i=x;i<=n;i++){
		int s=i-x;
		if(x*a[i]-pre[i]+pre[s]<=m)return 1;
	}
	return 0;
}
int ef(){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		} 
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	cout<<ef();
}
