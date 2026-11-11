#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],d[500010],maxi;
long long fin(long long l,long long r,long long o){
	if(l==r) return l;
	long long mid=(l+r)>>1;
	long long maxn=0;
	for(long long i=mid+1;i<=o;i++) maxn+=d[i]*(i-mid);
	if(maxn>m) return fin(mid+1,r,o);
	if(m!=0&&maxn==m) return mid;
	 return fin(l,mid,o);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		maxi=max(maxi,i-fin(1,i,i)+1);
	}
	cout<<maxi;
	return 0;
}
