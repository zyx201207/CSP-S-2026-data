#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;ll k;
ll a[N],pre[N];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,ans=0;
	for(int r=1;r<=n;r++){
		while(l<=r && a[r]*(r-l+1)-pre[r]+pre[l-1]>k){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
} 
