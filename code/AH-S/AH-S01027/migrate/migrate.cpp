#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
const int N=2000005;
const ll oo=0x3f3f3f3f3f3f3f3fll;
int c,ttt,ss,tt,res,cnt,n;
ll d,x[N];
int rpos[N];
ll f[305][305];
ll zyycnt[305][305];
void dfs(int now,int sum){
	if(now==tt){
		if(res==sum)++cnt;
		else if(sum<res)cnt=1,res=sum;
		return ;
	} 
	for(int j=now+1;j<=tt;++j){
		if(x[j]-x[now]<=d){
			dfs(j,sum+1);
		}
	}
}
void work(){
	cin>>n>>d;ll mx=0,mn=oo;
	rep(i,1,n){
		cin>>x[i];if(i==1)continue;
		mx=max(mx,x[i]-x[i-1]);
		mn=min(mn,x[i]-x[i-1]);
	} 
	if(mx<d||mn>d){
		cout<<0<<'\n';
		return ;
	}
	if(c==1||c==2){
		int ans=0;
		for(ss=1;ss<=n;++ss){
			for(tt=ss+1;tt<=n;++tt){
//				continue;
				cnt=0;res=0x3f3f3f3f;
				dfs(ss,0);ans+=(cnt==2);
//				cout<<res<<' ';
			} 
//			cout<<'\n';
		} cout<<ans<<'\n';
		return ;
	} if(c>=3&&c<=6){
		rep(i,1,n)rep(j,1,n)f[i][j]=oo,zyycnt[i][j]=0;
		rep(i,1,n)f[i][i]=0,zyycnt[i][i]=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				if(x[j]-x[i]<=d){
					f[i][j]=1,zyycnt[i][j]=1;
				} 
			}
		} 
		rep(k,1,n){
			rep(i,1,n){
				rep(j,1,n){
					if(i==j||j==k||i==k)continue;
					if(f[i][k]+f[k][j]==f[i][j])++zyycnt[i][j];
					else if(f[i][k]+f[k][j]<f[i][j]){
						zyycnt[i][j]=1ll*zyycnt[i][k]*zyycnt[k][j];
						f[i][j]=f[i][k]+f[k][j];
					}
				}
			} 
		} int ans=0;
			rep(i,1,n){
				rep(j,1,n){
					if(zyycnt[i][j]==2&&f[i][j]<oo)++ans;
				} 
			} cout<<ans<<'\n';
		return ;
	} x[n+1]=oo;
	rep(i,1,n){ 
		rpos[i]=upper_bound(x+i+1,x+n+1,x[i]+d)-x-1;
	} 
	if(c==11||c==12){
		ll dd=x[2]-x[1];
		ll sp=(d/dd),ans=0;
		if(sp==0)exit(ttt);
		rep(i,1,n-sp-1){
			ll p1=i+2ll*sp;
//			if(p1<n)ans+=1ll*(n-p1);
			ll cntp=(n-i-1ll)/sp;
			if(i+sp+sp-1<=n)++cntp;
			if(-cntp+n-i-sp<0)continue;
			ans+=(-cntp+(n-(i+sp)));
		} 
		cout<<ans<<'\n';
		return ;
	}
	if(c==13||c==14){
		ll ans=0;
		rep(i,1,n){
			int rr=rpos[i];
			if(rpos[i]==n)break;
			int tx=rpos[i]-1;
			if(tx==0||tx==i)continue;
			int p1=rpos[tx],p2=rpos[tx-1];if(p1==p2)continue;
			ans+=p1-p2;
		} cout<<ans<<'\n';
		return ;
	}
//	if(){
//		
//		return ;
//	}
}
int main(){
	 freopen("migrate.in","r",stdin);
	 freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>ttt;
	while(ttt--){
		work();
	}
	return 0;
}
