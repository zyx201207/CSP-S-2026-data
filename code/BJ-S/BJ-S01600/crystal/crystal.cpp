#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans=0;
long long qian[500005];
bool check(int x,int from){
    long long sum=qian[from]-qian[x-1];
    //要求差值
    long long cha=(from-x+1)*a[from]-sum;
    return cha<=m;
}
map<long long,long long> mp;
void dfs(int x){
    if(x==m+1){
        mp.clear();
        for(int i=1;i<=n;i++){
            mp[a[i]]++;
        }
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        a[i]+=1;
        dfs(x+1);
        a[i]-=1;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    qian[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //abc处
    }
    if(n<=5){
        dfs(1);
        cout<<ans;
        return 0;
    }
    //V2正解
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        qian[i]=qian[i-1]+a[i];//bug:原本放在 abc 处了！！！！
    }
    //a是不下降序列
    for(int i=1;i<=n;i++){
        /*
        //以a[i]为基准值，则只有1~i参加，且i-1是最近的
        long long test_num=m,cnt=1;//最多升级cnt个，而a[i]本身就满足
        for(int j=i-1;j>=1;j--){
            //那么a[j]可以看看能不能升级
            if(a[i]-a[j]<=test_num){
                //可以升级
                cnt++;
                test_num-=a[i]-a[j];
            }else{
                //连最近的都不可以升级，后面的肯定不可以升级，故直接跳过
                break;
            }
        }
        ans=max(ans,cnt);
        //这是v1版本，我觉得可以把这个做成二分。
        *///现在来到V2了，我觉得可以把上面的做成二分答案
        long long l=1,r=i;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(mid,i)){
                ans=max(ans,i-mid+1ll);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
6 0
1 1 1 1 1 1
*/
//100pts nb666
//实在不行有暴力部分分
