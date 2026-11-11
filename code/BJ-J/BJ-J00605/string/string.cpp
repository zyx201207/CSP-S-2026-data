#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
    int n;
    cin>>n;
    vector<pair<ll,char>>a;
    for(int i=0;i<n;i++){
        ll in;
        char c;
        cin>>in>>c;
        if(a.size()&&a.back().second==c){
            a.back().first+=in;
        }else a.push_back({in,c});
    }
    vector<pair<ll,char>>a1,a2;
    while(a.begin()!=a.end()){
        if(a.front().first>a.back().first){
            a2.push_back(a.back());
            a1.push_back({a.back().first,a.front().second});
            a.front().first-=a.back().first;
            a.erase(a.end()-1,a.end());
        }else{
            a1.push_back(a.front());
            a2.push_back({a.front().first,a.back().second});
            a.back().first-=a.front().first;
            a.erase(a.begin(),a.begin()+1);
        }
    }
    ll ans=0;
    for(int i=0;i<a1.size();i++){
        if(a1[i].second!=a2[i].second)ans+=a1[i].first;
    }
    cout<<ans;
    return 0;
}
