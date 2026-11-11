#include <bits/stdc++.h>
using namespace std;

int n,ans=1;
long long ar[510001],m;
bool flag=1,flag2=1;

bool check(int st,int ed){
	if((ed-st)*1ll*(ar[ed]-ar[ed-1])-(ar[ed-1]-ar[st-1])<=m) return 1;
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&ar[i]);
		if(ar[i]!=ar[1]) flag=0;
		if(i==1) continue ;
		if(ar[i]-ar[i-1]!=ar[2]-ar[1]) flag2=0;
	}
	if(flag==1){
		printf("%d",n);
		return 0;
	}
	if(flag2==1){
		long long xch=ar[2]-ar[1];
		printf("%d",int((1+sqrt(1+8*m/xch))/2));
		return 0;
	}
	sort(ar+1,ar+n+1);
	for(int i=1;i<=n;i++) ar[i]+=ar[i-1];
	for(int i=2;i<=n;i++){
		int l=1,r=i,ret=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)) ret=mid,r=mid-1;
			else l=mid+1;
		}
		if(ret!=-1) ans=max(i-ret+1,ans);
	}
	printf("%d",ans);
	return 0;
}
