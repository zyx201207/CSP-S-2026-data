#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=2e6+100;

int c,t,n,w[kMaxN],s[kMaxN][3],W[kMaxN];
ll d,x[kMaxN],ans;
bool f[kMaxN],g[kMaxN];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  for(cin>>c>>t;t--;){
    cin>>n>>d,ans=0,fill(s[0],s[n]+3,0);
    for(int i=1;i<=n;i++){
      cin>>x[i];
    }
    for(int i=1,j=1;i<=n;i++){
      for(;j<n&&x[j+1]-x[i]<=d;j++);
      w[i]=j,f[i]=i>1&&x[w[i]]-x[i-1]<=d&&(i==2||x[w[i]]-x[i-2]>d);
      g[i]=i<2||x[w[i]]-x[i-1]>d;
      W[i]=i>1?int(upper_bound(x+i+1,x+n+1,x[i-1]+d)-x):i+1;
    }
    for(int i=1,j,k;i<n;i++){
      if(w[i]==i)continue;
      s[w[i]][0]++,g[i]&&(s[w[i]][0]+=s[i][0],s[w[i]][2]+=s[i][0]*(i>1&&x[w[i]-1]-x[i-1]<=d),s[w[i]][1]+=s[i][1]),f[i]&&(s[w[i]][1]+=s[i][0]-s[i][2]);
      j=W[i];
      ans+=1ll*max(w[i]-j+1,0)*s[i][1];
      if(i>1){
        k=i>2?int(upper_bound(x+i+1,x+n+1,x[i-2]+d)-x):i+1,j--;
        ans+=1ll*max(j-k+1,0)*(s[i][0]-s[i][2]);
      }
    }
    cout<<ans<<'\n';
  }
	return 0;
}