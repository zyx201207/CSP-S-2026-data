#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Fro(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=2e5+10;
int n,m,ans,a[N];
vector<int> vec,tmp;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    For(i,1,n) cin>>a[i],vec.push_back(a[i]);
    Fro(i,30,0){
        tmp.clear();
        For(j,0,vec.size()-1){
            if(vec[j]&(1ll<<i)) tmp.push_back(vec[j]);
        }
        if(tmp.size()<m) continue;
        else vec=tmp;
    }
    ans=vec[0];
    For(i,1,min(m,(int)(vec.size()-1))) ans&=vec[i];
    cout<<ans;
    return 0;
}
