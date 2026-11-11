#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e6+7;
int n,ans;
ll m,a[N],s[N];
int find(int R){
	int l=1,r=R;
	while(l<r){
		int mid=(l+r)/2;
		if((R-mid+1)*a[R]-(s[R]-s[mid-1])<=m) r=mid;
		else l=mid+1; 
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int r=1;r<=n;r++) ans=max(ans,r-find(r)+1);
	printf("%d\n",ans);
	return 0; 
}
