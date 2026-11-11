#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;
    int a;
    char c;
    vector<pair<long long,char>> v;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        if(!v.empty())
            if(v.back().second==c)
                v.back().first+=a;
            else
                v.push_back({(long long)a,c});
        else
            v.push_back({(long long)a,c});
        sum+=a;
    }
    vector<pair<long long,char>> fr,bk;
    long long cur=0;
    for(int i=0;i<v.size();i++){
        if(cur+v[i].first>sum/2&&cur<sum/2)
            fr.push_back({sum/2-cur,v[i].second}),
            bk.push_back({v[i].first-(sum/2-cur),v[i].second});
        else if(cur+v[i].first<=sum/2)
            fr.push_back({v[i].first,v[i].second});
        else
            bk.push_back({v[i].first,v[i].second});
        cur+=v[i].first;
    }
    reverse(bk.begin(),bk.end());
    if(sum&1)
        bk.back().first--;
    if(bk.back().first==0)
        bk.pop_back();
    long long ans=0,pf=0,pb=0;
    while(1){
        if(pf>=fr.size()||pb>=bk.size())
            break;
        if(fr[pf].first==bk[pb].first){
            if(fr[pf].second!=bk[pb].second)
                ans+=fr[pf].first;
            pf++,pb++;
        }
        else if(fr[pf].first>bk[pb].first){
            if(fr[pf].second!=bk[pb].second)
                ans+=bk[pb].first;
            fr[pf].first-=bk[pb].first;
            pb++;
        }
        else {
            if(fr[pf].second!=bk[pb].second)
                ans+=fr[pf].first;
            bk[pb].first-=fr[pf].first;
            pf++;
        }
    }
    cout<<ans;
    return 0;
}
