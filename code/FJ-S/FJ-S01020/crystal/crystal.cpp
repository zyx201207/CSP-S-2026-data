#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
#define N 500005
using namespace std;
int n,ans,m,a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=1,R=i,res=i;
		while(L<=R){
			int mid=(L+R)>>1;
			if(m>=a[i]*(i-mid+1)-(pre[i]-pre[mid-1]))
				res=mid,R=mid-1;
			else
				L=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
