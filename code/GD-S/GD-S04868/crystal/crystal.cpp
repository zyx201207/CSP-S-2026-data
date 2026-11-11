#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=5e5+10;
int n,m,a[N],ans;
bool check(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(i<=x){
            sum+=a[x]-a[i];
        }else{
            sum+=a[i-x]-a[i-1]+(a[i]-a[i-1])*(x-1);
        }
        if(i>=x&&sum<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){l=mid+1;ans=mid;}
        else{r=mid-1;}
    }
    printf("%lld\n",ans);
    return 0;
}
