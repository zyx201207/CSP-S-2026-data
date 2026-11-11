#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll,char> s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,sum=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll num;
        char c;
        cin>>num>>c;
        s[i].first=num;
        s[i].second=c;
    }
    for(ll i=0;i<n/2;i++){
        if(s[i].second!=s[n-1-i].second&&s[i].first>0&&s[n-1-i].first>0){
            if(s[i].first>=s[n-1-i].first){
                sum+=s[i].first;
                s[n-1-i-1].first-=(s[i].first-s[n-1-i].first);
                s[n-1-i].first=0;
            }else{
                sum+=s[n-i-1].first;
                s[i+1].first-=(s[n-i-1].first-s[i].first);
                s[i].first=0;
            }
        }else{
            bool flag=0;
            for(ll j=i+1;j<n-1-i;j++){
                if(s[j].second!=s[i].second&&s[j].first>0){
                    flag=1;
                }
            }
            if(flag==1){
                if(s[i].first>=s[n-1-i].first&&s[i].first>0&&s[n-1-i].first>0){
                    sum+=s[i].first-s[n-1-i].first;
                    s[i].first-=s[n-1-i].first;
                }else{
                    sum+=s[n-i-1].first-s[i].first;
                    s[n-i-1].first-=s[i].first;
                }
            }else{
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
