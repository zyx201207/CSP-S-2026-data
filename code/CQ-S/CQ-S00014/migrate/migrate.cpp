#include<bits/stdc++.h>
using namespace std;using ll=long long;
ll rd(ll x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=2e6+6;
int cid,n,to[N];
ll x[N],d;
ll f[N],g[N],sg[N];
void solve(){
	n=rd();d=rd();
	for(int i=1;i<=n;i++)x[i]=rd();
	to[n]=n;
	for(int i=n-1;i;i--){
		to[i]=to[i+1];
		while(x[to[i]]-x[i]>d)to[i]--;
	}
	ll ans=0;
	for(int s=1;s<=n;s++){
		ll cnt=0;
		f[s]=0;g[s]=1;sg[s]=1;sg[s-1]=0;
		for(int i=s+1,j=s,k=s;i<=n;i++){
			while(x[i]-x[j]>d)j++;
			if(j==i)break;
			k=max(j,k);
			while(k<i-1&&f[k+1]==f[j])k++;
			f[i]=f[j]+1;
			g[i]=min(3ll,sg[k]-sg[j-1]);
			sg[i]=sg[i-1]+g[i];
			if(g[i]==2)cnt++;
//			if(g[j]>=3)break;
		}
		ans+=cnt;
//		int t=s;
//		while(t<n&&to[t+1]==to[s])t++;
//		ans+=cnt*(t-s+1);
//		s=t;
	}
//	cerr<<"ANS: "<<ans<<endl;
	printf("%lld\n",ans);
//	for(int i=n-1;i;i--){
//		f[i]=f[to[i]]+to[i]-i;
//		g[i]=g[to[i]];
//		set<int> st;
//		for(int j=i+1;j<to[i];j++)if(to[j]>to[i])st.insert(to[j]);
//		for(int j=to[i]+1;j<=to[to[i]];j++)cnt[j]=0;
//		for(int j=i+1;j<=to[i];j++)if(to[j]>to[i]){
//			cnt[to[j]]++;
//		}
//		for(int j=to[to[i]];j;j--){
//			if(j<to[to[i]])cnt[j]+=cnt[j+1];
//			if(cnt[j]==2){
//				g[i]+=f[j];
//			}
//		}
//		f[i]-=st.size();
//	}
//	for(int i=1;i<=n;i++)cerr<<g[i]<<" ";
//	cerr<<endl;
//	ll ans=0;
//	for(int i=1;i<=n;i++)ans+=g[i];
//	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cid=rd();
	int t=rd();while(t--)solve();
	return 0;
}

/*
0 1
11 11
1 2 3 4 5 10 12 13 14 15 16
*/
