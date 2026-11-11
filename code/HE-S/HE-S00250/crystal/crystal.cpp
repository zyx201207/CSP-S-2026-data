#include <bits/stdc++.h>
#define ll long long
#define lll __int128 
using namespace std;
int const MN=500501;
int n,ans;
ll m,a[MN],b[MN];
bool check(int l,int r){
	lll k=(lll)a[r]*(r-l+1)+b[l-1]-b[r];
	if(k>(lll)m)return 0;
	return 1;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}ans=max(ans,i-l+1);
	}printf("%d",ans);
	return 0;
}
