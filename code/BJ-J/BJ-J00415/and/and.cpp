#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[35];
vector<int> v[35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int ttt=0;ttt<35;ttt++){
        for(ll i=0;i<n;i++){
            if(a[i]!=0){
                if((a[i]&1)==1){
                    cnt[1]++;
                    v[1].push_back(a[i]);
                }
                for(int j=2;j<35;j++){
                    if(((a[i]>>(j-1))&1)==1){
                        cnt[j]++;
                        v[j].push_back(a[i]);
                    }
                }
            }
        }
        int maxbit=0;
        bool b=1;
        for(int i=0;i<35;i++){
            if(cnt[i]>=m){
                maxbit=i;
                b=0;
                n=cnt[i];
            }
            cnt[i]=0;
        }
        if(b){
            cout<<ans;
            return 0;
        }
        ans+=(1<<(maxbit-1));
        a.clear();
        a.resize(0);
        for(ll i:v[maxbit]){
            a.push_back(i&(((1<<(maxbit-1))-1)));
        }
        for(int i=0;i<35;i++){
            v[i].clear();
            v[i].resize(0);
        }
    }
    cout<<ans;
    return 0;
}
//9:00T1 10:45T2 11:45 T3

