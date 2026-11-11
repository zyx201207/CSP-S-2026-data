#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],m,lst[N],pos[N],k,l,r,flag,ans[N],mx[N];
bool cmp(int x,int y){
    return pos[x]>pos[y];
}
namespace bl{
    int in[N],st[N],top;
    void solve(){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                while(in[a[j]])
                    in[st[top--]]=0;
                st[++top]=a[j];
                in[a[j]]=1;
            }
            for(int i=1;i<=m;i++){
                ans[i]+=in[i];
                in[i]=0;
            }
            top=0;
        }
        return;
    }
}
set<int>p;
struct T{
    int p,v;
    bool operator<(const T&b)const{
        if(p==b.p)return v>b.v;
        return p<b.p;
    }
};
vector<T>pp[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1])flag=0;
        lst[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    if(flag){
        for(int i=1;i<=m;i++)
            cout<<pos[i]<<' ';
        cout<<'\n';
        return 0;
    }
    if(m==1){
        cout<<n<<'\n';
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++)ans[a[i]]++;
        ans[a[n]]=n;
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        cout<<'\n';
        return 0;
    }
    if(n<=5050){
        bl::solve();
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        cout<<'\n';
        return 0;
    }
    p.insert(0);
    // for(int i=1;i<=m;i++){
    //     k=pos[id[i]];
    //     while(k){
    //         auto x=prev(p.lower_bound(k));
    //         cout<<k<<' '<<*x<<'\n';
    //         if(us[i]!=*x){
    //             us[i]=*x;
    //             ans[id[i]]+=k-max(*x,mx[i+1]);
    //         }
    //         p.insert(k);
    //         cout<<"insert : "<<k<<'\n';
    //         k=lst[k];
    //     }
    // }
    for(int i=n;i>0;i--){
        k=i;
        auto x=prev(p.lower_bound(k));
        pp[a[i]].push_back({*x,1});
        pp[a[i]].push_back({i,-1});
        p.insert(lst[k]);
        p.insert(k);
    }
    for(int i=1;i<=m;i++){
        sort(pp[i].begin(),pp[i].end());
        k=l=0;
        // cout<<"now : "<<i<<'\n';
        for(auto x:pp[i]){
            // cout<<x.p<<' '<<x.v<<'\n';
            if(k==0)l=x.p;
            k+=x.v;
            if(k==0)ans[i]+=x.p-l;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}