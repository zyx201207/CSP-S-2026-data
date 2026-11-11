#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
const int N=2e5+12;
pair<ll,char> p[N];
void solve(){
    ll n,num=0;
    cin>>n;
    f(i,1,n){
        ll ina;
        char inc;
        cin>>ina>>inc;
        if(inc!=p[num].second){
            num++;
            p[num].first=ina;
            p[num].second=inc;
        }
        else{
            p[num].first+=ina;
        }
    }
    ll l=1,r=num;
    ll ans=0;
    while(r-l>0){
        if(p[l].second!=p[r].second){
            if(p[l].first>p[r].first){
                ans+=p[r].first;
                p[l].first-=p[r].first;
                r--;
            }
            else if(p[l].first<p[r].first){
                ans+=p[l].first;
                p[r].first-=p[l].first;
                l++;
            }
            else if(p[l].first=p[r].first){
                ans+=p[l].first;
                l++;
                r--;
            }
        }
        else{
            if(p[l].first>p[r].first){
                p[l].first-=p[r].first;
                r--;
            }
            else if(p[l].first<p[r].first){
                p[r].first-=p[l].first;
                l++;
            }
            else if(p[l].first=p[r].first){
                l++;
                r--;
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    while(t--){
        solve();
    }
    return 0;
}
