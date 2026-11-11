#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[500005],c[500005],c2,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) c[i]=a[i+1]-a[i];
    int j=0;
    for(int i=0;i<n-1;i++){
        long long k=(i-j)+1;
        c2+=c[i];
        s+=(k)*c[i];
        while(s>m){
            s-=c2;
            c2-=c[j];
            j++;
        }
        ans=max(ans,k);
    }
    cout<<ans;
    return 0;
}
