#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
vector<int> v,v2;
int n,m,ans=0;
bool check(int a,int x){
    int x2=(1ll)<<x;
    if((a&x2)>0){
        return true;
    }
    return false;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=30;i>=0;i--){
        v2.clear();
        for(int j=0;j<v.size();j++){
            if(check(v[j],i)){
                v2.push_back(v[j]);
                //cout<<v[j]<<endl;
            }
        }
        //cout<<i<<' '<<v2.size()<<endl;
        if(v2.size()>=m){
            v=v2;
            ans+=(1ll)<<i;
        }
    }
    cout<<ans;
    return 0;
}
