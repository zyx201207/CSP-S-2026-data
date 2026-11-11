#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

typedef long long ll;
ll n,m,a[500005],cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<ll> b;
        map<ll,ll> c;
        ll e=0;
        for(int j=i;j<=n;j++){
            e++;
            ll s;
            if(c.count(a[j])>0){
                s=c.count(a[j]);
                for(int k=s;k<e;k++){
                    ll d=b[k];
                    c[d]=0;
                    b[k]=0;
                }
            }
            c[a[j]]=e;
            b.push_back(a[j]);
        }
        for(int j=1;j<=m;j++){
            if(c.count(j)>0){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

