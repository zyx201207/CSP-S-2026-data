#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool f=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){f=0; break;}
    }
    if(f){
        int q=a[2]-a[1];
        int sum=0,an=1;
        for(int i=1;i<=n;i++){
            if(sum+i*q>m){
                break;
            }else{
                sum+=i*q;
                an++;
            }
        }
        cout<<an;
        return 0;
    }
    sort(a+1,a+1+n);
    int ans=-1;
    for(int i=1;i<=n;i++){
        int an=0,sum=0;
        for(int j=i;j>=1;j--){
            int di=a[i]-a[j];
            if(sum+di>m) break;
            else{
                sum+=di;
                an++;
            }
        }
        ans=max(ans,an);
    }
    cout<<ans;
    return 0;
}
