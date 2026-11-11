#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=5e5+10;
ll dre[N],n,m,a[N],d[N];//d[i]表示第i个数与第一个大于他的数的差
/*priority_queue<Node> q;
bool operator < (const Node &a,const Node &b){
    return a.w>b.w;
}*/

inline bool check(ll mid){
    bool flag=false;
    for(register int i=1; i<=n-mid+1;i++){
        ll ans=0;
        for(register int j=i; j<=i+mid-2;j++){
            ans+=dre[j]-dre[i+mid-1];
        }
        if(ans<=m) {
            //cout<<i<<' '<<i+mid-1<<endl;
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    queue<ll>q;
    for(register int i=1; i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(register int i=1; i<=n;i++){
        if(q.empty()) q.push(i);
        else{
            while(a[i]>a[q.front()]&&!q.empty()){
                d[q.front()]=a[i]-a[q.front()];
                q.pop();
            }
            q.push(i);
        }
    }
    d[n]=0;
    for(register int i=n-1; i>=1;i--){
        if(a[i]==a[i+1]) dre[i]=dre[i+1];
        else dre[i]=d[i]+dre[i+1];
    }
   // for(register int i=1; i<=n;i++) cout<<dre[i]<<' ';
    //cout<<endl;


    ll l=0,r=N,ans=INT_MIN;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)==true){
            l=mid+1;
            ans=max(ans,mid);
        }
        else r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
