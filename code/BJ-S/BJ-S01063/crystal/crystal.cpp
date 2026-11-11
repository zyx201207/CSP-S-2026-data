#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
long long c[N];
int mx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    if(m>1e8){
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        long long d=a[1]-a[2];
        if(d<0) d*=-1;
        for(int i=1;i<=n;i++){
            if(((d+i*d)*i)/2>m){
                cout<<i-1;
                return 0;
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++){
        long long sum=0;
        int cnt=0;
        for(int j=1;i+j-1<=n;j++){
            cnt++;
            sum+=c[i+j-1]*j;
            if(sum>m) break;
        }
        mx=max(mx,cnt);
    }
    cout<<mx;
    return 0;
}