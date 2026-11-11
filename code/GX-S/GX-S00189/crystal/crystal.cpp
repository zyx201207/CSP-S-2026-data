#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    register int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)) {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x*f;
}
const int N=5001;
int n,m,ans;
int a[N],d[N][N];
bool check(int from,int to){
    int sum=0;
    for(int i=from;i<to;i++)
        sum+=d[i][to];
    return m>=sum;

}
int solve(int now){
    int l=now+1,r=n,k=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(now,mid)) k=mid,l=mid+1;
        else r=mid-1;
    }
    return k-now+1;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        a[i]=read();
        q.push(a[i]);
    }
    for(int i=n;i>=1;i--){
        a[i]=q.top();
        q.pop();
    }
    if(n>5000){
        int da=a[2]-a[1];
        int A=da,B=-da,C=-2*m;
        int delta=B*B-4*A*C;
        int ans=(sqrt(delta)-B)/(2*A);
        printf("%lld",ans);
        return 0;

    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            d[i][j]=a[j]-a[i];
    for(int i=1;i<=n;i++){
        int x=solve(i);
        ans=max(ans,x);
    }
    printf("%lld",ans);
    return 0;
}

