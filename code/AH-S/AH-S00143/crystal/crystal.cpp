#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m;
ll a[500001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	a[0]=a[1];
	int r=1;
	ll sum=0;
	int ans=0;
	for(int l=1;l<=n;l++){
		while(r<=n&&sum+(a[r]-a[r-1])*(r-l)<=m){
			sum+=(a[r]-a[r-1])*(r-l);
			r++;
		}ans=max(ans,r-l);
		sum-=(a[r-1]-a[l]);
	}printf("%d\n",ans);
}