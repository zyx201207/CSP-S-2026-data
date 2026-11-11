#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define _ 500005
using namespace std;//text needed
int n;
ll m,s[_],a[_],res,ans;
int main(){
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	rep(i,1,n)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n)
		s[i]=s[i-1]+a[i];
	rep(i,1,n){
		int l=1,r=i;
		res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-1-mid+1)-(s[i-1]-s[mid-1])<=m){
				res=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
//		cout<<i<<' '<<res<<endl;
		ans=max(ans,i-res+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
