#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int M=500005;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[M];
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int now=m;
		int top=i,sum=0;
		while(now>=a[i]-a[top]&&top>0)now-=a[i]-a[top],sum++,top--;
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}
