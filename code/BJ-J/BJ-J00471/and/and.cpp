#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,ans;
vector<int>a;
vector<int>tmp;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=30;i>=0;i--){
        for(auto x:a)if((x>>i)&1)tmp.push_back(x);
        if(tmp.size()>=m){
            ans+=(1<<i);
            while(!a.empty())a.pop_back();
            for(auto x:tmp)a.push_back(x);
        }
        while(!tmp.empty())tmp.pop_back();
    }
    cout<<ans;
    return 0;
}