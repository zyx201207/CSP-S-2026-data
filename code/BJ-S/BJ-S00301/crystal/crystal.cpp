//读错题意了，只需要合成一个就行，也没什么的，农一个O(nlogn)的就可以！
//一定要开long long!
#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m;
long long a[N];
long long sum[N];
bool check(long long l,long long r/*注意这里的r是i，不是最右端点，是最有端点+1*/){
    long long len=r-l;
    long long want=len*a[r];//从l-(r-1)这一段最终的和的目标为want
    long long sum1=sum[r-1]-sum[l-1];//这一区间内实际的和
    return want-sum1<=m;//假如这一区建立需要补充的东西足够就返回1，否则返回0
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long ans=1;
    for(long long i=2;i<=n;i++){
        //便利1-n，对于每一个数，把前面尽可能多的数凑成这个数，下面二分前面最多到哪里
        long long l=1,r=i-1;
        long long cnt=1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(mid,i)){
                r=mid-1;
                cnt=mid;
            }else{
                l=mid+1;
            }

        }
        ans=max(ans,i-cnt+1);
    }
    cout<<ans;
    return 0;
}