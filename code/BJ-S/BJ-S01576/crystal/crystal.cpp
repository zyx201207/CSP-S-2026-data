#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
ll cnt[500010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans,res=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]>res){
            res=cnt[a[i]];
            ans=a[i];
        }
    }
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]==cnt[a[i+1]]){
            flag=true;
        }
    }

    if(flag)ans=a[(n+1)/2];
    int ret=0;
    for(int i=1;i<=n;i++){
        int x=(ans-a[i]);
        if(x>0&&m>0){
            a[i]+=x;
            m-=x;
        }else{;
            break;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1])ret++;
    }
    cout << ret+1 << endl;
    return 0;
}