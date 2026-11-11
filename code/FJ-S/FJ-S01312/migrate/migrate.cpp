#include<bits/stdc++.h>
#define N 2000006
#define rep(i,a,b)     for(int i=(a);i<=(b);i++)
#define int long long 
using namespace std;
int c,T,n,d,x[N],nt[N],pr[N],ans,sp[N];
void solve(){
	cin>>n>>d;
	rep(i,1,n)	cin>>x[i];
	memset(nt,0,sizeof(nt));
	memset(pr,0,sizeof(pr));
	memset(sp,0,sizeof(sp));
	ans=0,x[n+1]=4e18;
	for(int i=n-1;i>0;i--){
		int r=upper_bound(x+1,x+n+2,x[i]+d)-x-1,l=upper_bound(x+1,x+n+2,x[i-1]+d)-x-1;
		if(l>i)	nt[i]=0;
		else	nt[i]=nt[r]+r-i;
	}
	for(int i=2;i<=n;i++){
		int r=lower_bound(x+1,x+n+2,x[i]-d)-x,l=lower_bound(x+1,x+n+2,x[i+1]-d)-x;
		if(l<i)	pr[i]=0;
		else	pr[i]=pr[r]+i-r;
		sp[i]=sp[i-1]+pr[i];
		if(r>=i-1)	continue;
		int L=lower_bound(x+1,x+n+1,x[r+1]-d)-x,R=lower_bound(x+1,x+n+1,x[r+2]-d)-x;
		ans+=(sp[R-1]-sp[L-1]+R-L)*(nt[i]+1);
	}
//	rep(i,1,n)	cout<<nt[i]<<' ';
//	cout<<'\n';
//	rep(i,1,n)	cout<<pr[i]<<' ';
/*	cout<<'\n'*/cout<<ans<<'\n';
}
signed main(){
	   ios::sync_with_stdio(0);
	   cin.tie(0);
	   freopen("migrate.in","r",stdin);
	   freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)	solve();
	return 0;
}
