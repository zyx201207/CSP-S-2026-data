#include<bits/stdc++.h>

using namespace std;

long long n,m,k=0,maxi=0;
long long lst[200005];
long long f[200005];
void check(long long x){
    long long cnt=0;
    vector<long long> v;
    for(int i=1;i<=n;i++){
        if((lst[i] & (1<<x)) && f[i]==maxi){
            cnt++;
            v.push_back(i);
        }
    }
    if(cnt>=m){
        maxi++;
        for(int i=0;i<v.size();i++){
            f[v[i]]++;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>lst[i];
        long long now=lst[i],cnt=0;
        while(now){
            cnt++;
            now>>=1;
        }
        k=max(k,cnt);
    }

    for(int i=k;i>=0;i--){
        check(i);
    }

    long long ans=(1<<30)-1;
    for(int i=1;i<=n;i++){
        if(f[i]==maxi){
            ans&=lst[i];
        }
    }

    cout<<ans;
    return 0;
}
