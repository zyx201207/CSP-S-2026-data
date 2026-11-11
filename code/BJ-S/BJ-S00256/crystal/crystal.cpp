#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
struct node{
    long long p,s,l;
}arr[500005];
bool cmp(node x,node y){
    return x.p<y.p;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    bool flag1=1;
    long long maxn=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxn=max(maxn,a[i]);
    }
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i])flag1=0;
    }
    sort(a+1,a+n+1);
    a[0]=0;
    for(int i=1;i<=n;i++)arr[i].p=a[i]-a[i-1],arr[i].s=i-1,arr[i].l=i;
    if(flag1==1){
        long long x=a[2]-a[1];
        for(int i=1;;i++){
            if(m>=2*i*x)m-=2*i*x,ans+=2;
            else if(m>=i*x){
                ans++;
                break;
            }else break;
        }
        cout<<ans;
        return 0;
    }
    if(n*maxn<=m){
        cout<<n;
        return 0;
    }
    long long ma=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long ar[j-i+5],cnt=0,an=1;
            for(int k=i;k<=j;k++){
                ar[k-i+1]=a[k];
            }
            sort(ar+1,ar+j-i+1);
            if((j-i+1)%2==0){
                long long x=ar[(j-i+1)/2];
                for(int k=i;k<=j;k++){
                    cnt+=(x-ar[k]);
                    if(cnt>m)break;
                    an++;
                }
            }else{
                long long x=ar[(j-i+1)/2+1];
                for(int k=i;k<=j;k++){
                    cnt+=(x-ar[k]);
                    if(cnt>m)break;
                    an++;
                }
            }
            if(ma<cnt)ma=cnt,ans=max(ans,an);
        }
    }
    cout<<ans;
    return 0;
}