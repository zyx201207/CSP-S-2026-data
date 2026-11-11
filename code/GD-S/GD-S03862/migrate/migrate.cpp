#include<bits/stdc++.h>
using namespace std;

#define N 2000005
long long T,ans,n,a[N],l,r,mid,d,k,t,temp,dp[N],c,w[N],sum[N];
long long p;

long long bf(long long x){
	l=0,r=n;
	while(l+1<r){
		mid=l+(r-l)/2;
		if(a[mid]>=x) r=mid;
		else l=mid;
		//cout<<x<<' '<<mid<<'\n';
	}
	return r;
}

long long ef(long long x,long long p){
	l=p;r=n;
	while(l+1<r){
		mid=l+(r-l)/2;
		if(dp[mid]<=x) l=mid;
		else r=mid;
	}
	return l;
}

bool check(long long u,long long v){
	for(long long i=1;i<=n;i++){
		w[i]=0;
		sum[i]=0;
	}
	dp[u]=0;sum[u]=1;w[u]=1;
	sum[u-1]=0;
	for(long long i=u+1;i<=v;i++){
		k=bf(a[i]-d);
		if(k==i) return false;
		k=max(u,k);
		dp[i]=dp[k]+1;
		t=k;
		while(dp[t]==dp[k]&&t<=i-1) w[i]+=w[t],t++;
	}
	return (w[v]==2);
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//p<<=62;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		//cout<<check(1,5);
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<i;j++){
				//cout<<j<<' '<<i<<"orz\n";
				p=check(j,i);
				ans+=p;
				//if(p==1) cout<<"niulai\n";
				//if(check(j,i)) cout<<j<<' '<<i<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
