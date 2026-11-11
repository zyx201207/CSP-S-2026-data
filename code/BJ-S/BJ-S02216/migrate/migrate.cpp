#include<bits/stdc++.h>
using namespace std;
bool method(long long u,long long v,long long d){
    long long ans=0,a[d+1],l=v-u,d1=d;
    for(int i=d;i>=1;i--){
        a[i]=l/i;
        l%=i;
        if(l==0)break;
    }
    for(int i=1;i<=d1;i++){
        ans+=a[i];
    }
    if(ans==2)return true;
    return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    long long ans[t];
    long long t1=t;
    while(t){
        ans[t1-t]=0;
        long long n,d;
        cin>>n>>d;
        long long x[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+d+1;j<=n;j++){
                if(method(x[i],x[j],d)){
                    ans[t1-t]++;
                }
            }
        }
        t--;
    }
    for(int i=0;i<t1;i++){
        if(i==t1-1)cout<<ans[i];
        else cout<<ans[i]<<endl;
    }
    return 0;
}