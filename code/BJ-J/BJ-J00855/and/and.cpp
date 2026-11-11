#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=1e9+7,INF=1e18;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=(1ll<<32);i>0;i/=2){
        vector<int> v;
        v.clear();
        for(int j=1;j<=n;j++){
            if((a[j]&i)!=0){
                v.push_back(a[j]);
            }
        }
        if(v.size()<m)continue;
        for(int j=i;j>0;j/=2){
            int cnt=0;
            for(int k=0;k<v.size();k++){
                if(v[k]&j){
                    cnt++;
                }
            }
            if(cnt>=m){
                vector<int> v1;
                for(int k=0;k<v.size();k++){
                    if(v[k]&j){
                        v1.push_back(v[k]);
                    }
                }
                v=v1;
            }
            if(cnt==m)break;
        }
        sort(v.begin(),v.end(),cmp);
        int ans=v[0];
        for(int j=1;j<m;j++){
            ans&=v[j];
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
