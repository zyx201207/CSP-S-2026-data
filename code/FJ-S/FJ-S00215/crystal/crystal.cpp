#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+3;
int n,ans=1;
ll m,a[N],s[N];

inline bool check(int x,int st){
	int ed=st+x-1;
	ll nd=s[ed-1]-s[st-1];
	if(a[ed]*(x-1)-nd<=m) return true;
	else return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=n-i+1,tmp=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				tmp=mid;
				l=mid+1;
			}else r=mid-1;
		}
		ans=max(ans,tmp);
	}
	printf("%d",ans);
	return 0;
}
