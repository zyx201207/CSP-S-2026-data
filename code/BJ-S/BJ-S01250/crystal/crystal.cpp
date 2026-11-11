#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
/*
给你一个序列，你可以操作至多m次将一些数字+1,求最后最多有多少数字可以是相同的
5e5
首先排序，注意到正确答案一定是原本序列中已经存在的某个值
可以直接去二分这个最大值，然后维护一个前缀和，去看每个元素的前k个元素能不能拼出来这个就好了
O(n log w)

14:42 finished 

*/
#define int ll
int n,m,a[N];
int s[N];
bool check(int k){
    for(int i=k;i<=n;i++){
        if(k*a[i]-(s[i]-s[i-k])<=m)return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=20;i>=0;i--){
        if(check(ans+(1ll<<i)))ans+=(1ll<<i);
    }
    cout<<ans<<endl;
    return 0;
}