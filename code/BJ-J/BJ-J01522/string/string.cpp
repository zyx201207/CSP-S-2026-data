#include<bits/stdc++.h>
using namespace std;
int n;
long long sa[200005],sb[200005],a[200005],b[200005];
char c[200005],d[200005];
long long cnt=0,ans=0,half;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        b[n-i+1]=a[i];
        d[n-i+1]=c[i];
    }
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1]+a[i];
        sb[i]=sb[i-1]+b[i];
    }
    half=sa[n]/2;
    for(int i=1,j=1;;){
        long long minn=min(sa[i],sb[j]);
        if(c[i]!=d[j]) ans+=minn-cnt;
        cnt=minn;
        if(sa[i]<sb[j]) i++;
        else if(sa[i]>sb[j]) j++;
        else i++,j++;
        if(cnt>=half) break;
    }
    cout<<ans;
    return 0;
}
