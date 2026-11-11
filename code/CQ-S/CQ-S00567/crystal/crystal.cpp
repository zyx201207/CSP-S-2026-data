#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010],sa[500010];
ll m;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sa[i]=a[i]+sa[i-1];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sa[i]-sa[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
/*
15:04 write
15:07 pass small
15:08 write tester
15:11 pass big
15:12 try hack
15:20 finish 
*/
