#include<bits/stdc++.h>
#define int long long
#define fst first
#define scd second
#define pb push_back
using namespace std;
const int N=5e5+100;
int n,m;
int a[N],pre[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int l=1,r;l+ans<=n;l++){
		r=l+ans;
		while(a[r]*(r-l+1)-(pre[r]-pre[l-1])<=m&&r<=n)ans++,r++;
	}
	cout<<ans;
	return 0;
}