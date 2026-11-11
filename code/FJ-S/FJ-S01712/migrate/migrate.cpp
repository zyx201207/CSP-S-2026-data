#include<bits/stdc++.h>
#define ll long long
#define N 2000010
using namespace std;
ll cnt,ans=0;
ll a[N],b[N],c[N],l[N],r[N];
void work1(ll n,ll m){
	if(n==1)return;
	ll i,j,x,y,z;
	cnt=0;
	for(i=1;i<=n;i=upper_bound(a+1,a+1+n,a[r[cnt]]+m)-a-1){
		cnt++;
		l[cnt]=r[cnt-1]+1,r[cnt]=i;
		if(i==n)break;
	}
	for(i=1;i<=cnt;i++)
		for(j=l[i];j<=r[i];j++)
			b[j]=i,c[j]=0;
	c[1]=1;
	for(i=1;i<=n;i++){
		for(j=r[b[i]]+1;a[j]<=a[i]+m&&j<=n;j++)
			c[j]+=c[i];
		if(c[i]==2)ans++;
	}
}
void work(ll n,ll m){
	while(n){
		work1(n,m);
		for(ll i=1;i<=n;i++)a[i]=a[i+1];
		n--;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll i,j;
	ll n,m,T;
	cin>>T>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
//		cout<<n<<" "<<m<<"\n";
		for(i=j=1;i<=n;i++,j++){
			cin>>a[j];
			if(j!=1&&a[j]-a[j-1]>m)work(j-1,m),j=1;
		}
		work(j-1,m);
		cout<<ans<<"\n";
	}
}
