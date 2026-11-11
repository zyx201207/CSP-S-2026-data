#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],pre[N],ans=0;
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
}
void work(){
	init();
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&(i-j+1)*a[i]-pre[i]+pre[j-1]>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	work();
	return 0;
} 
