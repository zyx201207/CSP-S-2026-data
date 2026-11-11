#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
    int a,sum;
}a[N];
int n,m,maxn=-1,sum=1<<30-1;
bool cmp(node a,node b){
    if(a.sum!=b.sum) return a.sum>b.sum;
    return a.a>b.a;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].a;
    if(m==2&&n<=2e4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) maxn=max(maxn,(a[i].a&a[j].a));
        }
        cout<<maxn;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int c=a[i].a;
        while(c){
            a[i].sum+=c%2;
            c/=2;
        }
    }
    for(int k=1;k<=1e8/m&&m+k-1<=n;k++){
        sum=a[k].a;
        for(int i=k+1;i<=m+k-1;i++) sum&=a[i].a;
        maxn=max(maxn,sum);
    }
    sum=a[n].a;
    for(int i=n-1;i>=n-m+1;i--) sum&=a[i].a;
    maxn=max(maxn,sum);
    sort(a+1,a+n+1,cmp);
    for(int k=1;k<=1e8/m&&m+k-1<=n;k++){
        sum=a[k].a;
        for(int i=k+1;i<=m+k-1;i++) sum&=a[i].a;
        maxn=max(maxn,sum);
    }
    sum=a[n].a;
    for(int i=n-1;i>=n-m+1;i--) sum&=a[i].a;
    cout<<max(sum,maxn);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
