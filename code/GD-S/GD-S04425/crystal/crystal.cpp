#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],cnt;
ll ans=1,maxl,maxr;
bool flag=1;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
	cerr<<flag;
	if(flag){
		int r=2;
		for(;r<=n;r++){
			cnt+=a[r-1];
			ll need=a[r]*(r-1)-cnt;
			if(need>m){
				break;
			}
		}
		cout<<r-1;
		return 0;
	}else{
		for(int r=1;r<=n;r++){
			ll l=r-1,need=0;
			for(;l>=1;l--){
				need+=a[r]-a[l];
				if(need>m) break;
			}
			ans=max(ans,r-l);
		}
		cout<<ans;
	}
	return 0;
}
