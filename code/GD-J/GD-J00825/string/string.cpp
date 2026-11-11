#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n;
int a[N];char c[N];
ll pre[N],suf[N];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=n;i;i--){
		suf[i]=suf[i+1]+a[i];
	}
	ll ans=0,mx=0;
	int l=0,r=n+1;
	while(l<=n && r>=1){
		if(pre[++l]>=suf[--r]){
			while(pre[l]>=suf[r]){
				ans+=(suf[r]-mx)*(c[l]!=c[r]);
				mx=suf[r];
				r--;
			}
			ans+=(pre[l]-mx)*(c[l]!=c[r]);
			r++;
			mx=pre[l];
		}
		else{
			while(pre[l]<suf[r]){
				ans+=(pre[l]-mx)*(c[l]!=c[r]);
				mx=pre[l];
				l++;
			}
			ans+=(suf[r]-mx)*(c[l]!=c[r]);
			l--;
			mx=suf[r];
		}
	}
	cout<<(ans>>1)<<"\n";
	return 0;
}
