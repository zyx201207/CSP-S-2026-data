#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=1e6+100;

int t,n,k,l,r,m,d[kMaxN],M[kMaxN],c[kMaxN],p[kMaxN],C,LL[kMaxN],rr[kMaxN],st[kMaxN],lo[kMaxN],CNT;
int qq[kMaxN];
bool g[kMaxN];
vector<int>e[kMaxN];
vector<pair<int,int>>o[kMaxN];

void dfs(int x,int f){
  d[x]=M[x]=0;
  for(int i:e[x]){
    if(i!=f){
      dfs(i,x),d[i]>d[x]?M[x]=d[x],d[x]=d[i]:(M[x]=max(M[x],d[i]));
    }
  }
  d[x]++;
}

void DFS(int x,int f){
  o[x].clear();
  for(int i:e[x]){
    o[x].push_back({d[i],i});
  }
  sort(o[x].begin(),o[x].end());
  int la=d[x];
  for(int i:e[x]){
    if(i!=f){
      d[x]=d[x]==d[i]+1?M[x]+1:d[x];
      d[i]--;
      d[x]>d[i]?M[i]=d[i],d[i]=d[x]:(M[i]=max(M[i],d[x]));
      d[i]++;
      DFS(i,x);
      d[x]=la;
    }
  }
}

bool Chk(){
  int cnt=n;
  for(int i=1;i<=n;i++){
    g[i]=m>1&&(o[i].size()<2||o[i][int(o[i].size())-2].first<m-1);
    cnt-=g[i];
  }
  if(cnt<=k){
    return 1;
  }
  for(int i=1;i<=n;i++){
    if(!g[i]){
      c[i]=0;
      for(int j:e[i]){
        c[i]+=!g[j];
      }
      cnt-=c[i]<2;
    }
  }
  if(cnt<=k){
    return 1;
  }
  for(int i=1;i<=n;i++){
    if(!g[i]&&c[i]!=2){
      for(int j:e[i]){
        if(!g[j]){
          p[C=1]=i;
          for(int k=j;;){
            p[++C]=k;
            if(c[k]==2){
              for(int l:e[k]){
                if(l!=p[C-1]&&!g[l]){
                  k=l;
                  break;
                }
              }
            }else{
              break;
            }
          }
          if(p[1]>p[C]){
            continue;
          }
          CNT=0;
          for(int i=3,j,k;i<=C;i++){
            j=o[p[i-1]].size()<3?0:o[p[i-1]][int(o[p[i-1]].size())-3].first;
            k=1;
            for(;CNT&&st[CNT]<=j+k;k+=lo[CNT--]);
            st[++CNT]=j,lo[CNT]=k,qq[CNT]=qq[CNT-1]+(j<m?min(k,m-j):0);
            LL[i]=qq[CNT];
          }
          CNT=0;
          for(int i=C-2,j,k;i>=1;i--){
            j=o[p[i+1]].size()<3?0:o[p[i+1]][int(o[p[i+1]].size())-3].first;
            k=1;
            for(;CNT&&st[CNT]<=j+k;k+=lo[CNT--]);
            st[++CNT]=j,lo[CNT]=k,qq[CNT]=qq[CNT-1]+(j<m?min(k,m-j):0);
            rr[i]=qq[CNT];
          }
          for(int i=1;i<C;i++){
            if(cnt-min((i<2?0:LL[i+1]),i-1-(c[p[1]]==1))-min((i==C-1?0:rr[i]),C-1-i-(c[p[C]]==1))<=k){
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  for(cin>>t,cin>>t;t--;){
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++){
      cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    }
    if(n==k){
      fill(e,e+n+1,vector<int>());
      cout<<"0\n";
      continue;
    }
    dfs(1,0),DFS(1,0),l=1,r=n-1;
    for(;l<=r;){
      m=l+r>>1;
      if(Chk()){
        r=m-1;
      }else{
        l=m+1;
      }
    }
    cout<<l<<'\n';
    fill(e,e+n+1,vector<int>());
  }
	return 0;
}