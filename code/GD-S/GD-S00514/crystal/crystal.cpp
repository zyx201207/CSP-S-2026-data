#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int ans;
int flag;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int sum=0;
	int l=1,r=2;
	for(r;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		if(sum>m){
			flag=1;
			ans=max(ans,r-l);
			while(sum>m){
				sum-=(a[r]-a[l]);
				l++;
			}
		}
	}
	if(!flag)cout<<n;
	else cout<<ans;
} 
