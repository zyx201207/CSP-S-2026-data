#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<numeric>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int cid,T,n,ans;
long long d;
int rt[5005],it[5005],dis[5005][5005];
long long x[2000005],cnt[5005][5005],s[5005][5005];
int main() {
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w+",stdout);
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin>>cid>>T;
  while(T--) {
    cin>>n>>d;
    for(int i=1;i<=n;i++)
      cin>>x[i];
    for(int i=1;i<=n;i++) {
      rt[i]=i+1;
      for(;rt[i]<=n && x[rt[i]]-x[i]<=d;rt[i]++);
      --rt[i];
	}
    for(int i=1;i<=n+1;i++)
      for(int j=1;j<=n+1;j++) {
        dis[i][j]=0x3F3F3F3F;
        s[i][j]=cnt[i][j]=0;
	  }
	for(int i=1;i<=n;i++) {
	  dis[i][i]=0;
	  it[i]=i;
	  s[i][i]=1;
	}
	for(int len=2;len<=n;len++)
	  for(int l=1,r;l+len-1<=n;l++) {
	    r=l+len-1;
	    dis[l][r]=dis[min(rt[l],r)][r]+1;
	  }
	ans=0;
	for(int len=2;len<=n;len++)
	  for(int l=1,r;l+len-1<=n;l++) {
	    r=l+len-1;
	    it[r]=min(it[r],rt[l]);
	    for(;it[r]>=1 && dis[it[r]][r]==dis[min(rt[l],r)][r];--it[r]);
	    it[r]++;
	    cnt[l][r]=s[it[r]][r]-s[min(rt[l],r)+1][r];
	    if(cnt[l][r]==2)
	      ans++;
	    s[l][r]=s[l+1][r]+cnt[l][r];
	  }
	cout<<ans<<'\n';
  }
}

