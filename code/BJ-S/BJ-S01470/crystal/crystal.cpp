#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans=0,cnt=0,lz=1e9,pos=0;
bool flag=true,fi=true;
struct sum{
    ll pow;
    ll cz;
};
sum a[500010];
bool cmp(sum a,sum b){
    return a.pow<b.pow;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i].pow;
        if(i!=1&&a[i].pow!=a[i-1].pow&&flag)flag=false;
        if(i>2&&a[i].pow-a[i-1].pow!=a[i-1].pow-a[i-2].pow&&fi)fi=false;
        cnt+=a[i].pow;
    }
    if(flag){//L
        cout<<n;
        return 0;
    }
    if(fi&&a[n].pow-a[n-1].pow==1){//A
        ll cha=a[n].pow-a[n-1].pow,maxx=0,ps=0;
        for(ll i=1;i<=n;i++){
            if(maxx+i*cha>m){
                ps=i;
                break;
            }
            else maxx+=i*cha;
        }
        cout<<ps;
        return 0;
    }
    if(fi){//B
        ll cha=a[n].pow-a[n-1].pow,maxx=0,ps=0;
        for(ll i=1;i<n;i++){
            if(maxx+i*cha>m){
                ps=i-1;
                break;
            }
            else maxx+=i*cha;
        }
        cout<<min(cha*(n-1),ps);
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ll midf=cnt/n;
    for(ll i=n;i>=1;i--){
        a[i].cz=abs(a[i].pow-midf);
        if(a[i].cz<lz){
            lz=a[i].cz;
            pos=i;
        }
    }
    ll midl=a[pos].pow;
    for(ll i=1;i<=n;i++){
        a[i].cz=abs(midl-a[i].pow);
    }
    ll bu=m;
    while(bu>0&&pos>0){
        if(a[pos].cz<=bu)ans++;
        bu-=a[pos].cz;
        pos--;
    }
    cout<<ans;
    return 0;
}
