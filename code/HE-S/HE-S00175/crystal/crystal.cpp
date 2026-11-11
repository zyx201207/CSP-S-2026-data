#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long n,m,k,q,sum,maxn=1;
void solve(){
    cin>>n>>m;
    bool b=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            q=a[i]-a[1];
        }else if(i>2){
            if(a[i]-a[i-1]!=q){
                b=1;
            }
        }
    }
    sort(a+1,a+n+1);
    if(b){
        for(int i=2;i<=n;i++){
            k=m;
            sum=1;
            for(int j=i-1;j>=1;j--){
                if(a[i]-a[j]>k){
                    break;
                }else{
                    sum++;
                    k-=(a[i]-a[j]);
                }
            }
            maxn=max(maxn,sum);
        }
    }else{
        for(int i=n-1;i>=1;i--){
            if(a[n]-a[i]>m){
                break;
            }else{
                m-=(a[n]-a[i]);
                maxn++;
            }
        }
    }
    cout<<maxn;
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}
