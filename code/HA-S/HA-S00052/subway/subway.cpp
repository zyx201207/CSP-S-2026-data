#include<bits/stdc++.h>
using namespace std;
int k,z[50005];
int c,n,m,d,q;
int a,t;
int w[10005];
int x[10005],y[10005];
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++){
  	cin>>w[i];
  }
  for(int i=1;i<=n;i++){
      cin>>k;
      while (k--){
      	cin>>a>>t;
      	z[a]=t;
      	
      }
  }
  for(int i=1;i<=q;i++){
  	cin>>x[i]>>y[i];
  	cout<<z[x[i]]+w[x[i]]+z[y[i]]+w[y[i]]<<'\n';
  	
  }
  return 0;
}


