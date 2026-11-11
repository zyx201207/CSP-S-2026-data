#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int k;
const int N=2e5+5;
int a[N]={};
int used[N]={};
bool cmp(int l,int r){
    return l>r;
}
vector<int> v;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    int ax=0;
    int ax1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int p=a[i]&(-a[i]);
        ax1=max(ax1,a[i]);
        if(p==0){
            used[i]=1;
            ax=max(ax,a[i]);
            v.push_back(a[i]);
        }
    }
    sort(a+1,a+n+1,cmp);
    if(n-v.size()>=k){
        int ans=0x3f3f3f3f3f3f;
        for(int i=1;i<=n;i++){
            if(k<=0) break;
            if(!used[i]){
                ans=ans&a[i];
                k--;
            }
        }
        cout<<ans<<'\n';
    }else{
        int ans=0x3f3f3f3f3f3f;
        for(int i=1;i<=n;i++){
            if(!used[i]){
                ans=ans&a[i];
                k--;
            }
        }
        for(int i=0;i<v.size();i++){
            if(k<=0) break;
            if(ans&v[i]==1) k--;
        }
        if(k>0) cout<<0;
        else cout<<ans<<'\n';
    }
    return 0;
}
