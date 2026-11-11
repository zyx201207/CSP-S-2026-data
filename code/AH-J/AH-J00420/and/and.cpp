#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,ans;
vector<int> v;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),cmp);
    ans=v[0];
    int cnt=0;
    for(int i=1;i<=n;i++){
            if(ans&v[i]!=0){
                ans=ans&v[i];
                cnt++;
            }
            if(cnt==m){
                break;
            }
    }
    cout<<ans;
    return 0;
}
