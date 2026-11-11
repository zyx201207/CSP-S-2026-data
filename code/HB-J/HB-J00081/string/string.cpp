#include <bits/stdc++.h>

using namespace std;

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    fastio();

    auto f1 = freopen("string.in","r",stdin);
    auto f2 = freopen("string.out","w",stdout);

    int n;
    cin>>n;
    vector<pair<int,char>> v;
    int p=n;
    while (p--)
    {
        int a;
        cin>>a;
        char c;
        cin>>c;
        v.push_back({a,c});
    }
    int ans=0;
    int l=0,r=n-1;
    while (l<r)
    {
        if(v[l].first>0&&v[r].first>0){
            if(v[l].second==v[r].second){
                int d=min(v[l].first,v[r].first);
                v[l].first-=d;
                v[r].first-=d;
            }else{
                int d=min(v[l].first,v[r].first);
                v[l].first-=d;
                v[r].first-=d;
                ans+=d;
            }
        }else {
            if (v[l].first==0)
            {
                l++;
            }
            if(v[r].first==0){
                r--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}