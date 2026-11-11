#include<bits/stdc++.h>
using namespace std;

struct node{
   int u,v;
};

void solve(){
   int n,k;
   cin>>n>>k;
   vector<node> a(n-1);
   for(int i=0;i<n;i++) cin>>a[i];
   int ans=0;
   for(int i=0;i<n;i++){
      if(a[i].v-a[i].u==1){
        ans++;
      }
   }
   cout<<ans+1<<'\n';
}

int main(){
   freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   int c,t;
   cin>>c>>t;
   while(t--){
      solve();
   }

   return 0;
}
