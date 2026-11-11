#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
//    cout<<1<<endl;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    cout<<1<<endl;
    for(int i=1;i<=n;i++){
        printf("%lld ",a[i]);
    }
    return 0;
    int l=0,r=n+1;
    while(l+1<r){
        int mid=(l+r)/2;
        long long sum=0;
        int f=0;
        for(int i=1;i<=mid;i++){
            sum=sum+a[mid]-a[i];
            if(sum>m){
                r=mid;
                f=1;
                break;
            }
        }
        if(f==1) continue;
        if(sum<=m){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<1<<endl;
    if(l==0) printf("1");
    else{
        printf("%d",l);
    }
    return 0;
}
