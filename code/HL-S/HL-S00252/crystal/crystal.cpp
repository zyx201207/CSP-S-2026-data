#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
int n,ans=0;
ll m;
ll a[N],s[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		//s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		//ll need;
		int l=1,r=i;
		int pos=i;
		while(l<=r) { //尝试二分，求可选最远 
			int mid=l+r>>1; //表示当前可选到mid 
			ll cur=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(cur<=m) //尝试更远
				pos=min(pos,mid),
				r=mid-1;
			else 
				l=mid+1; 
		}
		ans=max(ans,i-pos+1);
	}
	printf("%d",ans);
	return 0;
}

