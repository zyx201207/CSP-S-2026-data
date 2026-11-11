#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=1,pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;pre[1]=a[1];
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		while(a[i]*(i-j+1)-pre[i]+pre[j-1]>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
} 
