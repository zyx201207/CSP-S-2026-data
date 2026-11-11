#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,string> > v;
ll n,a=0,i,j,s=-1,ans=0;
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    i=0;
    j=n-1;
    while(v[i].first!=0&&v[j].first!=0){
        if(v[i].first>v[j].first){
            if(v[i].second!=v[j].second){
                ans+=v[j].first;
            }
            v[i].first-=v[j].first;
            v[j].first=0;
            j--;
        }
        else if(v[i].first==v[j].first){
            if(v[i].second!=v[j].second){
                ans+=v[j].first;
            }
            v[i].first-=v[j].first;
            v[j].first=0;
            v[i].first=0;
            j--;
            i++;
        }
        else{

            if(v[i].second!=v[j].second){
                ans+=v[i].first;
            }
            v[j].first-=v[i].first;
            v[i].first=0;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
