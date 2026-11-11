#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,char>a[200005];
ll l,r;
ll n;
ll ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    l=1,r=n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    while(l<r){
        if(a[l].first==a[r].first&&a[l].second==a[r].second){
            l++;
            r--;
        }
        else if(a[l].first==a[r].first&&a[l].second!=a[r].second){
            ans+=a[l].first;
            l++;
            r--;
        }
        else if(a[l].first>a[r].first){
            if(a[l].second!=a[r].second){
                ans+=a[r].first;
            }
            a[l].first-=a[r].first;
            r--;
        }
        else if(a[l].first<a[r].first){
            if(a[l].second!=a[r].second){
                ans+=a[l].first;
            }
            a[r].first-=a[l].first;
            l++;
        }
    }
    cout<<ans;
return 0;
}
