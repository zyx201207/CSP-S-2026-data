#include<bits/stdc++.h>
using namespace std;
long long n,m,card[50010],ans[50010],q[50010],r,l;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++)q[i]=0;
        cin>>card[i];
    }
    for(int i=1;i<=n;i++){
        l=i;
        r=i-1;
        for(int j=i;j<=n;j++){
                r++;
                q[r]=card[j];
                for(int k=l;k<r;k++){
                    if(q[k]==q[r]){
                        r=k;
                        break;
                    }
                }
        }
       for(int i=l;i<=r;i++)ans[q[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    }
int main(){
    ios::sync_with_stdio(false);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
    }
