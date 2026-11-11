#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int cnt[78],sum;
void fj(int x){
    int t=-1;
    while(x){
        t++;
        cnt[t]+=x%2;
        x/=2;
    }
    return ;
}
struct A{
    int w,v;
}ans[N];
bool cmp1(A x,A y){
    return x.w>y.w;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i].v=a[i];
        fj(a[i]);
    }
    for(int i=30;i>=0;i--){
        for(int j=1;j<=n;j++){
            int po=(1<<i);
                if(cnt[i]>=m) ans[j].w=ans[j].w*2+a[j]/po;
            a[j]%=po;
        }
    }
    sort(ans+1,ans+n+1,cmp1);
    sum=ans[1].v;
    for(int i=2;i<=m;i++){
        sum=sum&ans[i].v;
    }
    cout<<sum;
    return 0;
}
