#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define WZH_Local
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
int t=1;
int n,m,x;
int ans;
vector<int>v;
vector<int>check(vector<int>ve,int now){
    int num=0;
    for(auto i:v) num+=((i>>now)&1);
    if(num<m) return ve;
    ans+=(1<<now);
    vector<int>ret;
    ret.clear();
    for(auto i:v)
        if((i>>now)&1)
            ret.push_back(i);
    return ret;
}
int main(){
    #ifndef WZH_Local
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    #endif
    //cin>>t;
    while(t--){
        cin>>n>>m;
        For(i,1,n){
            cin>>x;
            v.push_back(x);
        }
        foR(i,30,0){
            v=check(v,i);
            // cout<<i<<'\n';
            // for(auto j:v) cout<<j<<' ';
            // cout<<'\n';
        }
        cout<<ans;
    }
    return 0;
}
