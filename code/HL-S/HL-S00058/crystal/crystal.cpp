#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(m>=1ll*a[i]*(i-mid)-(s[i-1]-s[mid-1])) r=mid;
			else l=mid+1;
		}
		mx=max(mx,i-l+1);
	}
	printf("%d",mx);
	return 0;
}