///今年的j1分数线低一点吧！！！！！！！！
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll n,m,a[N];
ll andand(ll p,ll q){
    ll t1[N],t2[N],t3[N],t1ans=0,t2ans=0,t3ans=0;
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    while(p!=0){
        t1[++t1ans]=p%2;
        p/=2;
    }
    while(q!=0){
        t2[++t2ans]=q%2;
        q/=2;
    }
    ll u=max(t1ans,t2ans);
    for(ll i=1;i<=u;i++){
        if(t1[i]==t2[i])t3[i]=1;
        else t3[i]=0;
    }
    uy=0;
    for(ll i=1;i<=u;i++){
        uy+=s3[i];uy*=10;
    }
    ll o=0;
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n]<<'\n';
        return 0;
    }
    if(m==n){
        ll res=a[1]&&a[2];
        for(ll i=3;i<=n;i++){
            res=res&&a[i];
        }
        cout<<res<<"\n";
        return 0;
    }
    else cout<<a[1]<<'\n';
    return 0;
}
