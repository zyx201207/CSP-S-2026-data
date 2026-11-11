#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e6+10;
int dp[N],dp1[N],nxt[N];
ll c[N],d;
int cil(int c1,int c2){return c1/c2+(c1%c2!=0);}
int fnd(int l,int r,int x){
	if(l==r) return l;
	int mid=cil(l+r,2);
	if(c[mid]-c[x]<=d) return fnd(mid,r,x);
	return fnd(l,mid-1,x);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,T;
	scanf("%d%d",&cid,&T);
	while(T--){
		int n,x;
		ll ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&c[i]);
		if(cid<=10){
			for(int i=1;i<=n;i++){
				int l=i;
				for(int j=1;j<=n;j++) dp[j]=1e9,dp1[j]=0;
				dp[i]=0,dp1[i]=1;
				for(int j=i+1;j<=n;j++){
					while(l<j&&c[l]+d<c[j]) l++;
					if(l>=j) break;
					dp[j]=dp[l]+1,dp1[j]+=dp1[l];
					if(l+1<j&&dp[l+1]==dp[l]){
						dp1[j]+=dp1[l+1];
						if(l+2<j&&dp[l+2]==dp[l]) dp1[j]+=dp1[l+2];
					}
					if(dp1[j]==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
		else{
			for(int i=1;i<=n;i++)
				if(c[i]-c[1]<=d&&c[n]-c[i]<=d){x=i;break;}
			for(int i=1;i<x;i++) nxt[i]=fnd(i,n,i);
			for(int i=1;i<x;i++){
				if(nxt[i]-x==1) ans+=n-nxt[i]-(nxt[x-1]-nxt[i]);
				else if(nxt[i]==x) ans+=nxt[x-1]-x-(nxt[x-2]-x)*(x-2>0);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
