#include <bits/stdc++.h>

using namespace std;

//TLE  :(

void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    fastio();

    auto f1 = freopen("card.in","r",stdin);
    auto f2 = freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> a(n);               //shun xu
    for(int i=0;i<n;++i)cin>>a[i];

    vector<int> v;
    vector<int> cnt(m+1,0);

    for(int i=0;i<n;++i){           //di i ju

        v.clear();
        for(int j=i;j<n;++j){
            auto it = find(v.begin(),v.end(),a[j]);
            if(it != v.end()) {
                v.erase(it,v.end());
            }
            v.push_back(a[j]);
        }
        
        for(auto x:v){
            cnt[x]++;
        }
    }

    for(int i=1;i<=m;++i){
        cout<<cnt[i]<<" ";
    }

    cout<<endl;
    return 0;
}