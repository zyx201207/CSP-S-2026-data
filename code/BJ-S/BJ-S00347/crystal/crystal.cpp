#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],sum[N],ans[N];
long long maxn=-1e12-1;
int main(){
    freopen("crystal.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    sum[1]=0;
    ans[1]=1;
    for(int i=2;i<=maxn;i++){
        int j=1;
        while(a[j]<=i){
            sum[i]+=i-a[j];
            ans[i]++;
            j++;
        }
        if(sum[i]>m){
            break;
        }
    }
    long long p=0;
    for(int i=1;i<=maxn;i++){
        p=max(p,ans[i]);
    }
    freopen("crystal.out","w",stdout);
    cout<<p;
}
