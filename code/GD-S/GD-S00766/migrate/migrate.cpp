#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x&-x)
const int N=2e6+5;
ll a[N],d;int R[N],L[N],t[N],n,vis[N];
int get(int x,int y){
	if(x==y)return 0;
	int res=0;
	while(R[x]<y)x=R[x],++res;
	return res+1;
}
void clr(){for(int i=1;i<=n;i++)t[i]=0;}
void upd(int x,int d){++x;for(;x<=n+1;x+=lowbit(x))t[x]+=d;}
int ask(int x){++x;if(x<0)return 0;int res=0;for(;x;x-=lowbit(x))res+=t[x];return res;}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	bool F=1;
	for(int i=3;i<=n;i++)
		F&=(a[i]-a[i-1]==a[i-1]-a[i-2]);
	if(F){
		d=(ll)(d/(a[2]-a[1]))*(a[2]-a[1]);
		ll ans=0;
		for(int i=1;i<=n;i++){
//			int x=lower_bound(a+1,a+1+n,a[i]+d)-a,y=lower_bound(a+1,a+1+n,a[i]+2*d)-a;
//			if(x<y)ans+=y-1-x;
			if(a[n]>=a[i]+2*d-(a[2]-a[1])&&d>a[2]-a[1])++ans;
		}
		cout<<ans<<'\n';
		return;
	}
	if(n<=300){
		for(int i=1;i<=n;i++){
			int l=i+1,r=n,mid;
			while(l<=r)mid=l+r>>1,(a[mid]-a[i]<=d?l=mid+1:r=mid-1);
			--l;R[i]=l;
			l=1,r=i-1;
			while(l<=r)mid=l+r>>1,(a[i]-a[mid]<=d?r=mid-1:l=mid+1);
			++r;L[i]=r;
		}
//		ll ans=0;
//		for(int i=1;i<=n;i++)
//			for(int j=i+1;j<=n;j++){
//				int u=j,ct=0;bool fl=0;
//				for(int k=1;k<=n;k++)vis[k]=0;
//				while(u>i){
//					if(L[u]==u){fl=1;break;}
//					vis[u]=1,u=L[u];
//				}
//				if(fl)break;
//				for(int k=2;k<=n;k++)vis[k]+=vis[k-1];
//				u=i;
//				while(u<j){
//					ct+=vis[R[u]-1]-vis[u];
//					u=R[u];
//				}
//				cerr<<i<<' '<<j<<' '<<ct<<'\n';
//				ans+=(ct==2);
//			}
//		cout<<ans<<'\n';
//		return;
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int mn=0,ct=0,nw=j;bool fl=0;
				upd(0,1);
				int tim=i;vis[i]=1;
				while(R[tim]<j){
					if(R[tim]==tim){fl=1;break;}
					tim=R[tim],vis[tim]=1,++mn;
				}++mn;
				if(fl){
					for(int i=1;i<=n;i++)
						vis[i]=t[i]=0;
					break;
				}
				for(int k=j-1;k>=i;k--){
					while(nw>=R[k]&&R[k]!=j)upd(get(nw,j),-1),nw--;
					if(vis[k])ct+=ask(mn-get(i,k)-1);
					upd(get(k,j),1);
				}
				clr();
				for(int k=1;k<=n;k++)vis[k]=0;
				if(ct==2)++ans;
			}
		cout<<ans<<'\n';
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;cin>>c>>_;
	while(_--)solve();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4

0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/
