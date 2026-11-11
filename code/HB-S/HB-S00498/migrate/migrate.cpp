#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ull unsigned long long
#define eb emplace_back
#define umap unordered_map
#define ll long long
#define Fast1 ios::sync_with_stdio(0)
#define Fast2 cin.tie(0),cout.tie(0)
#define int long long
//观察 1：鸟只会往前飞
//观察 2：如果 (x,y) 不是，那么 (x,z) (z>y) 也不是
//所以可以对于每个 x 二分出最大的满足条件的 y
//观察 3:如果 (x,y) 不是,那么 (l,r) (l<x,r>y) 也不是
//所以对于上一个 x 二分出来的结果 y,下次二分的时候从 y 开始
//所以可以直接双指针了,只需要判断 n 次是不是
//考虑怎么判断 [l,r] 是不是
//我们发现如果 [l,r] 可以抵达
//并且不存在 [l',r'] 使得不能直接到,并且有大于 2 种方法可以 2 步到
//那么 [l,r] 是合法的,所以把所有 [l',r'] 丢掉就可以了
//至于第一个约束可以把所有间距大于 d 的断开就行了
//考虑怎么找 [l',r'],显然我们只需要极小的 [l',r']
//可以对于每个 l 二分最小的 r 使得有大于 2 个路径
//就可以做到 O(n^2 log n) 了
//考虑怎么对所有合法的记数
//读错题了每崩主
const int N=2e6+5;
int a[N],c,f[N],g[N],n,d;
bool chk(int l,int r){
    for(int i=l;i<=r;i++)f[i]=1e18,g[i]=0;
    f[l]=0;g[l]=1;
    for(int i=l+1;i<=r;i++){
        for(int j=i;j>=l;j--){
            if(a[i]-a[j]>d)break;
            f[i]=min(f[i],f[j]+1);
        }
        for(int j=i;j>=l;j--){
            if(a[i]-a[j]>d)break;
            if(f[j]+1==f[i])g[i]++;
        }
    }return g[r]==2;
}
int solve(int l,int r){
    int y=l,res=0;
    for(int i=l;i<=r;i++){
        chk(i,n);
        for(int j=i+1;j<=r;j++)
            res+=g[j]==2;
    }
    return res;
}
void _(){
    cin>>n>>d;
    if(n==1||n==2){cout<<"0\n";return;}
    for(int i=1;i<=n;i++)cin>>a[i];
    int lst=1,ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]>d)ans+=solve(lst,i-1),lst=i;
    }if(lst!=n)ans+=solve(lst,n);cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    Fast1;Fast2;int t=1;
    cin>>c>>t;
    while(t--)_();
}
