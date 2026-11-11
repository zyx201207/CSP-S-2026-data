#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=0;
	int ans=1,k=1;
	int head=1;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+(i-head)*(a[i]-a[i-1]);
		while(pre[i]>m){
			pre[i]-=a[i]-a[head];
			head++;
		}
		ans=max(ans,i-head+1);
	}
	cout<<ans;
}
