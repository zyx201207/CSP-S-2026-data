#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long k[N];
long long t[N];
long long s[N];
long long f[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    sort(t+1,t+1+n);
    long long ans=0;
    for(int i=1;i<=n-1;i++){
        k[i]=t[i+1]-t[i];
        f[i]=f[i-1]+k[i];
        s[i]=s[i-1]+f[i];
    }
    int l=1,r=1;
    long long sum=0;
    long long len=1;
    while(r<=n){
        while(sum>m&&l<=r){
            if(k[l]!=k[l+1]){
                sum-=k[l]*(r-l);
            }
            l++;
            len--;
        }
        ans=max(len,ans);
        //cout<<sum<<" "<<len<<"\n";
        r++;
        len++;
        if(t[r]!=t[r-1]){
            sum+=f[r-1]-f[l-1];
        }
    }
    cout<<ans;
    return 0;
}
