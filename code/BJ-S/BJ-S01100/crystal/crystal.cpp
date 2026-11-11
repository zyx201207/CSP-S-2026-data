#include<bits/stdc++.h>
#define int long long
#define MAX 1000010
using namespace std;
int a[MAX];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    int maxn=-9e18,minn=9e18;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
        if(a[i]==i) cnt++;
    }
    if((maxn-minn)*n>1e8){
        int i=a[n/2+1];
        vector<int> v;
        for(int j=1;j<=n;j++){
            v.push_back(abs(a[j]-i));
        }
        sort(v.begin(),v.end());
        int sum=0;
        int ans=0;
        for(int j=0;j<v.size();j++){
            if(sum+v[j]<=m){
                sum+=v[j];
                ans++;
            }else break;
        }
        cout<<ans;
        return 0;
    }
    int ans=0;
    for(int i=minn;i<=maxn;i++){
        vector<int> v;
        for(int j=1;j<=n;j++){
            v.push_back(abs(a[j]-i));
        }
        sort(v.begin(),v.end());
        int sum=0;
        int as=0;
        for(int j=0;j<v.size();j++){
            if(sum+v[j]<=m){
                sum+=v[j];
                as++;
            }else break;
        }
        ans=max(ans,as);
    }
    cout<<ans<<"\n";
    return 0;
}
