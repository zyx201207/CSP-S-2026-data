#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cassert>
#define ll long long
#define pii pair<int,int> 
#define pli pair<long long,int>
#define pil pair<int,long long>
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
using namespace std;
const int N1=5005,N=2e6+5;
int Ctest,test;
int n;
ll d,a[N];//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！N1 
int fl[N],fr[N];
ll check(int l,int r){
	long long s1=0,s2=0;
	int u=l;
	while(fr[u]<r){
		if(u==fr[u]) return 0;
		s1+=1ll*fr[u];
		u=fr[u];
	}
	u=r;
	while(fl[u]>l){
		if(u==fl[u]) return 0;
		s2+=1ll*fl[u];
		u=fl[u];
	}
	if(s1-s2==1) return 1;
	return 0;
	//恰好=1！记得删掉！！！！！！！！！！！！！！！ 
}
int dp[N][2];
int find1(int l,int r,int x){
	int res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(fl[mid]>=x) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
int find2(int l,int r,int x){
	int res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(fl[fl[mid]]>=x) res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
/*

0 1
6 5
6 8 10 13 14 17 

*/
int main(){
//	freopen("data.in","r",stdin);
//	freopen("my.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>Ctest>>test;
	while(test--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int lst=1;
		for(int i=1;i<=n;i++){
			while(lst<=i&&a[i]-a[lst]>d) ++lst;
			fl[i]=lst;
		}
		lst=n;
		for(int i=n;i>0;i--){
			while(lst>=i&&a[lst]-a[i]>d) --lst;
			fr[i]=lst;
		}
		ll ans=0;
		dp[n][0]=dp[n][1]=0;
		for(int i=n-1;i>0;i--){
			if(fr[i]==n){
				dp[i][0]=dp[i][1]=0;
				int p1,p2,p3;
				p1=find2(i+1,fr[i],fl[i]);p2=find1(i+1,fr[i],i-1);p3=find1(i+1,fr[i],i);
				//p1 [i+1,fr[i]]第一个fl[fl[x]]>=fl[i]的   p2 [i+1,fr[i]]第一个fl[x]>=i-1   p3第一个fl[x]>=i
				if(p3>0) dp[i][0]+=1ll*(fr[i]-p3+1);
				if(p2>0){
					if(fl[fl[p2]]>=fl[i]){
						if(p3>0) dp[i][1]+=1ll*(p3-p2);
						else dp[i][1]+=1ll*(fr[i]-p2+1);
					}
				}
				dp[i][1]+=dp[i][0];
				continue;
			}
			dp[i][0]=dp[i][1]=0;
			if(fr[i]==i) continue;
			//[fr[i]+1,fr[fr[i]]] p1第一个 fl[x]>=fr[i]-1 p2第一个fl[x]>=fr[i]
			int p1=find1(fr[i]+1,fr[fr[i]],fr[i]-1),p2=find1(fr[i]+1,fr[fr[i]],fr[i]),p3;
			if(p1>0){
				if(p2==0) ans+=1ll*(fr[fr[i]]-p1+1);
				else ans+=1ll*(p2-p1);
			}
			if(fl[fr[fr[i]]]==fr[i]) ans+=1ll*(dp[fr[fr[i]]][1]-dp[fr[fr[i]]][0]);
			else if(fl[fr[fr[i]]]==fr[i]-1) ans+=1ll*dp[fr[fr[i]]][0];
			p1=find2(i+1,fr[i],fl[i]);p2=find1(i+1,fr[i],i-1);p3=find1(i+1,fr[i],i);
			//p1 [i+1,fr[i]]第一个fl[fl[x]]>=fl[i]的   p2 [i+1,fr[i]]第一个fl[x]>=i-1   p3第一个fl[x]>=i
			if(p3>0) dp[i][0]+=1ll*(fr[i]-p3+1);
			//if(p2>p3) cout<<p2<<' '<<p3<<'\n';
			//if(p2>p3) assert(fl[fr[i]]>=i);
			//assert(p2<=p3);
			if(p2>0){
				if(fl[fl[p2]]>=fl[i]){
					if(p3>0) dp[i][1]+=1ll*(p3-p2);
					else dp[i][1]+=1ll*(fr[i]-p2+1);
				}
			}
			dp[i][1]+=dp[i][0];
			if(fl[fr[i]]==i){
				dp[i][0]+=dp[fr[i]][0];
				dp[i][1]+=dp[fr[i]][1];
			}else{
				if(!(fl[fr[i]]<i-1||fl[fl[fr[i]]]<fl[i])){
					dp[i][1]+=dp[fr[i]][0];
				}
			}
			//cout<<ans<<'\n';
		}
		//for(int i=1;i<=n;i++) cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
		cout<<ans<<'\n';
		//clear！！！！！！！！！！！！！ 
	}

	return 0;
}
/*

0 1
6 2
-4 -3 -2 -1 3 6

*/
