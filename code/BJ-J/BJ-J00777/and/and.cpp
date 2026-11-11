#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int ans=-1e9;
int a[N];
bool st[N];
vector<int> b;
void dfs(int x){
    if(x>m){
        int sum=0;
        for(int i=0;i<b.size();i++){
            if(i==0){
                sum=b[i];
            }else{
                sum&=b[i];
            }
        }
        ans=max(ans,sum);
    }else{
        for(int i=1;i<=n;i++){
            if(!st[i]){
                b.push_back(a[i]);
                st[i]=true;
                dfs(x+1);
                b.pop_back();
                st[i]=false;
            }
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}
