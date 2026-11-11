#include<bits/stdc++.h>
using namespace std;
int n,a[200005],an[200005],bn[200005];
char c[200005];
long long ant,bnt,cnt,b[200005],now,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin >> c[i];
        b[i]=b[i-1]+a[i];
        //printf("%d ",a[i]);
        cnt+=a[i];
    }
    int l=0,r=n+1,mid;
    while(l+1<r){
        mid=(l+r)/2;
        if(b[mid]>cnt/2){
            r=mid;
        }else{
            l=mid;
        }
    }
    bnt=n-r+1;
    ant=r;
    for(int i=1;i<r;i++){
        an[i]=a[i];
    }
    an[r]=cnt/2-b[r-1];
    for(int i=1;i<n-r+1;i++){
        bn[i]=a[n-i+1];
    }
    bn[n-r+1]=b[r]-(cnt-1)/2+1;
    for(int i=1;i<=r;i++){

        while(an[i]>=bn[now]){
            if(c[n-now+1]!=c[i]){
                ans+=bn[now];
            }
            an[i]-=bn[now];
            now++;
        }
        if(c[n-now+1]!=c[i]){
            ans+=an[i];
        }
        bn[now]-=an[i];
    }
    printf("%lld",ans);
}
