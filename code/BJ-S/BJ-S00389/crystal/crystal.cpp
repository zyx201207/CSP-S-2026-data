#include <iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
const int maxn=1e7+5;
ll n,m;
ll idx[maxn];
pair<ll,ll> p[maxn];
pair<ll,ll> b[maxn];
bool vis[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n;
    cin>>m;
    ll tmp=0;
    for(int i=1;i<=n;i++){
        cin>>p[i].first;
        tmp+=p[i].first;
    }
    tmp/=n;
    for(int i=1;i<=n;i++){
        if(p[i].first>tmp)p[i].first=0x3f3f3f3f;
    }
    for(int i=1;i<=n;i++){
        b[i].first=abs(p[i].first-tmp);
        b[i].second=i;
    }
    ll minn=0x3f3f3f3f;
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        idx[i]=b[i].second;
    }
    ll tmp1=0;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        tmp1+=b[i].first;
        if(tmp1<=m){
            //cout<<"success:"<<b[idx[i]].first<<" ";
            cnt++;
        }
        else break;
    }
    cout<<cnt;
    return 0;
}
