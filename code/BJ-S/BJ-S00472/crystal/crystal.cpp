#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll N,M;
const ll kMax=1e6;
ll a[kMax+5];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>N>>M;
    for(ll i=1;i<=N;i++){
        cin>>a[i];
    }
    sort(a+1,a+N+1);
    ll j=1,sum=0,ans=1;
    for(ll i=1;i<=N;i++){
        sum+=a[i];
        if(i==N||a[i]!=a[i+1]){
            while(a[i]*(i-j+1)-sum>M){
                sum-=a[j];
                j++;
            }
            ans=max(ans,i-j+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}

