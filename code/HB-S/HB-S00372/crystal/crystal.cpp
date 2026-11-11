#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll d[N],s[N];

bool check(int x,int y){
	if(x>y)swap(x,y);
	return 1ll*(a[y]*(y-x)-(s[y-1]-s[x-1]))<=m;
}
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(n-i+1<=ans)break;
		int l=0,r=n+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				l=mid;
			}else{
				r=mid;
			}
		}
		ans=max(ans,l-i+1);
	}
	printf("%d",ans);
    return 0;
}
