#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000],l,r,mid,ans=0,adding[510000],from,begin[510000],tot=1;
bool check(long long x,long long y){
	if(m>=(y-x+1)*a[y]-adding[y]+adding[x-1]) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(adding,0,sizeof(adding));
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) adding[i]=adding[i-1]+a[i];
	begin[tot]=1;
	for(int p=2;p<=n;p++){
		if(a[p]!=a[p-1]) begin[++tot]=p;
	}
	begin[++tot]=n+1;
	for(int p=2;p<=tot;p++){
		l=1;r=begin[p]-1;
		while(l<r){
			mid=(l+r)/2;
			if(check(mid,begin[p]-1)){
				ans=max(ans,begin[p]-mid);
				r=mid;
			}
			else l=mid+1;
		}
	
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 5
1 1 1 8 9

7 10
-100 1 1 1 1 1 2

*/
