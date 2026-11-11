#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],a2[200005],b[200005],b2[200005],pos,sum,l,r,ans;
char c[200005],c2[200005];
long long ch(long long x,long long y){
    long long xx=b[x-1],yy=b2[y-1];
    x=b[x],y=b2[y];
    return max(0ll,min(x,y)-max(xx,yy));
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        b[i]=b[i-1]+a[i];
        sum+=a[i];
    }
    pos=upper_bound(b+1,b+n+1,sum/2)-b;
    for(int i=n;i>pos;i--){
        a2[n+1-i]=a[i];
        c2[n+1-i]=c[i];
    }
    if(b[pos-1]<ceil(sum/2.0)){
        a2[pos]=b[pos]-ceil(sum/2.0);
        c2[pos]=c[pos];
        b[pos]=ceil(sum/2.0);
        a[pos]=ceil(sum/2.0)-b[pos-1];
    }
    for(int i=1;i<=pos;i++)b2[i]=b2[i-1]+a2[i];
    for(int i=1;i<=pos;i++){
        cout<<a[i]<<c[i]<<a2[i]<<c2[i]<<"\n";
    }
    for(int i=1,j=1;i<=pos;i++){
        if(c[i]!=c2[j])ans+=ch(i,j);
        while(b2[j]<b[i])j++;
    }
    cout<<ans;
    return 0;
}
