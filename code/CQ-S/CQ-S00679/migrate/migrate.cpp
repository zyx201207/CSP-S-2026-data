#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int cid,T,n,fa1[N],fa2[N],top1[N],top2[N],sum1[N],sum2[N];
#define ll long long
ll D,a[N];
vector<int> G1[N],G2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cid>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1,j=1;i<=n;++i){
			while(j<=n&&a[j]-a[i]<=D) ++j;
			fa1[i]=j-1;
			if(fa1[i]!=i) G1[fa1[i]].push_back(i);
		}
		for(int i=n,j=n;i;--i){
			while(j&&a[i]-a[j]<=D) --j;
			fa2[i]=j+1;
			if(fa2[i]!=i) G2[fa2[i]].push_back(i);
		}
		for(int i=n;i;--i){
			bool ok=0;
			for(int j:G2[i]) if(j==fa1[i]) {ok=1;break;}
			if(ok) top1[i]=top1[fa1[i]];
			else top1[i]=i;
			sum1[i]=(fa1[i]==i?0:sum1[fa1[i]])+(int)G2[i].size();
		}
		for(int i=1;i<=n;++i){
			bool ok=0;
			for(int j:G1[i]) if(j==fa2[i]) {ok=1;break;}
			if(ok) top2[i]=top2[fa2[i]];
			else top2[i]=i;
			sum2[i]=(fa2[i]==i?0:sum2[fa2[i]])+(int)G1[i].size();
		}
		ll ans=0;
		for(int i=1;i<n;++i){
			if(fa1[i+1]!=i+1&&fa2[i]!=i){
				int t1=i+1,t2=i,op1=0,op2=0;
				for(int j:G2[i]){
					if(j==fa1[i+1]) t1=top1[j];
					if(j==i+1) op1=1;
				}
				for(int j:G1[i+1]){
					if(j==fa2[i]) t2=top2[j];
					if(j==i) op2=1;
				}
				int cnt1=sum1[i+1]-sum1[t1]+(int)G2[i].size()-op1;
				int cnt2=sum2[i]-sum2[t2]+G1[i+1].size()-op2;
				ans+=1ll*cnt1*cnt2;
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;++i) G1[i].clear(),G2[i].clear();
	}
	return 0;
}

