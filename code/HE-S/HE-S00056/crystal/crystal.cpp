#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],k[N],cnt[N],sum[N];
long long s=0;
long long n,m;
long long get(long long d){
	long long res=0;
	long long j=0;
	while(res<=m){
		res+=j*d;
		j++;
	}
	return j-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n>5000){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long d=a[2]-a[1];
		cout<<get(d);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(!cnt[a[i]]){
			k[++s]=a[i];
		}
		cnt[a[i]]++;
	}
	sort(k+1,k+1+s);
	long long res=0,cost=m;
	long long ans=0;
	int ma=0;
	int pl;
	for(int i=1;i<=s;i++){
		cost=m;
		pl=i;
		ans=cnt[k[pl]];
		for(int j=pl-1;j>0;j--){
			cost-=(cnt[k[j]]*(k[pl]-k[j]));
			if(cost<0) break;
			ans+=cnt[k[j]];
		}
		res=max(res,ans);
	}
	cout<<res;
	return 0;
}
