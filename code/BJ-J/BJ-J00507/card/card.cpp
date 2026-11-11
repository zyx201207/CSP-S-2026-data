#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll maxn=5e5+5,maxm=3e5+5;
ll n,m,a[maxn],ans[maxm];
bool f[5005],fa=1;//maxn?
//unordered
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i]){
            fa=0;
        }
    }
   // if(n<=5000){
        for(ll i=1;i<=n;i++){
            memset(f,0,sizeof f);
            stack<ll> s;
            for(ll j=i;j<=n;j++){
                if(f[a[j]]==0){
                    f[a[j]]=1;
                    s.push(a[j]);
                }else{
                    while(!s.empty()&&s.top()!=a[j]){
                        f[s.top()]=0;s.pop();
                    }
                }
            }
            while(!s.empty()){
                ans[s.top()]++;
                s.pop();
            }
        }
        for(ll i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }cout<<"\n";
  //  }else{
  //      if(fa==1){
   //         ll b[maxm];
   //         memset(b,0,sizeof b);
  //          for(ll i=1;i<=n;i++){
   //             b[a[i]]++;
   //         }for(ll i=1;i<=n;i++){
   //             b[a[i-1]]--;
   //             if(b[a[i-1]]==0){
   //
   //             }
   //         }
   //     }
  //
  //  }
    return 0;
}
