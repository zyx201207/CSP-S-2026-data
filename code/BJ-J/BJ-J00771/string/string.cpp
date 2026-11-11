#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans=0,d[1000005],num=0;
long long L[200005],R[200005],b[1000005],cnt=0,col[1000005];
long long le[1000005],rt[1000005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);/*zhushi!!!!!!!!!!!!!!!!!!!*/
    scanf("%lld",&n);
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        L[i]=m+1;
        scanf("%lld",&a[i]);
        m+=a[i];
        R[i]=m;
        cin>>c[i];
        b[++cnt]=L[i];
        b[++cnt]=R[i];
    }
    for(int i=1;i<=n;i++){
        b[++cnt]=m+1-L[i];
        b[++cnt]=m+1-R[i];
    }
    sort(b+1,b+1+cnt);
    for(int i=1;i<=cnt;i++){
        if(b[i]!=b[i-1])d[++num]=b[i];
    }

    for(int i=1,j=1;i<=num;i++){
        le[i]=d[i];
        rt[i]=d[i+1]-1;
        while(R[j]<le[i])j++;
        col[i]=c[j]-'0';
    }
    rt[num]=m;
    long long l=1,r=num;
    while(l<r){
        if(col[l]!=col[r])ans+=rt[l]-le[l]+1;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
