#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool isA=1,isB=1,isC=1;

unordered_map<ll,bool>c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    ll n,m;cin>>n>>m;
    vector<ll>a(n);

    if(n<=5000) isA=0,isB=0,isC=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=i) isA=0;
        if(i>=2 and a[i]-a[i-1]!=a[i-1]-a[i-2]) isB=0;
        if(fabs(a[i])>100) isC=0;
    }

    if(isA or isB){
        sort(a.begin(),a.end());
        ll prefix=1,cost=0;
        for(int i=0;i<n-1;i++){
            ll need=prefix*(a[i+1]-a[i]);
            if(cost+need>m or need<0){
                break;
            }
            cost+=need;
            prefix++;
        }
        cout<<prefix<<endl;
    }else if(isC){
        sort(a.begin(),a.end());

        int ans=0;
        for(int i=1;i<n;i++){
            if(c[a[i]]) continue;
            c[a[i]]=1;
            ll cost=0;
            int pre=1;
            for(int j=i-1;j>=0;j--){
                ll need=a[i]-a[j];
                if(cost+need>m) break;
                cost+=need;
                pre++;
            }
            ans=max(pre,ans);
        }
        cout<<ans<<'\n';
    }else if(n<=6000){
        sort(a.begin(),a.end());

        int ans=0;
        for(int i=1;i<n;i++){
            ll cost=0;
            int pre=1;
            for(int j=i-1;j>=0;j--){
                ll need=a[i]-a[j];
                if(cost+need>m) break;
                cost+=need;
                pre++;
            }
            ans=max(pre,ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
