#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=0;
long long bl(long long x,long long y,long long z){
    for(int i=y+1;i<=n;i++){
        if((a[i]-a[y])*b[y]>m){
            continue;
        }
        x-=(a[i]-a[y])*b[y];
        b[i]+=b[y];
        z++;
        ans=max(bl(x,i,z),ans);
        b[i]-=b[y];
        x+=(a[i]-a[y])*b[y];
        z--;
    }
    return max(z,ans);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            if(a[i]>a[j]){
                int k=a[j];
                a[j]=a[i];
                a[i]=k;
                break;
            }
        }
    }
    for(int i=1;i<n;i++){
        ans=max(ans,bl(m,i,1));
    }
    cout<<ans<<endl;
    return 0;
}
