#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> card,ans,su;
vector<bool> of;
void solve(){
    ll n,m;
    cin>>n>>m,ans=card=vector<ll>(n+10,0),of=vector<bool>(m+10,false),su=vector<ll>(m+10,-1);
    for(int i=1;i<=n;i++)
        cin>>card[i];
    for(int s=1;s<=n;s++){
        for(int i=s;i<=n;i++){
            if(of[card[i]]==true){
                for(int j=i-1;card[j]!=card[i];j--)
                    of[card[j]]=false;
            }
            else
                of[card[i]]=true;
        }
        for(int i=1;i<=m;i++)
            ans[i]+=of[i];
        of=vector<bool>(m+10,false);
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
}