#include<bits/stdc++.h>
using namespace std;
#define MAXN 500500
int n,l,r,ans=1;
long long m,sum;
long long a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    while(r<n){
        while(l<r&&sum>m){
            sum=sum-(a[r]-a[l+1]);
            l++;
        }
        while(r<n&&sum<=m){
            if(l!=r) sum=sum+(a[r+1]-a[r])*(r-l);
            r++;
        }
        if(sum<=m) ans=max(ans,r-l);
        else ans=max(ans,r-l-1);
    }
    cout<<ans;
    return 0;
}
/*
14:20 这里是AH-S00323，代号蒟蒻
      正在为您实时播报安师大第二考场情况
      虽然没什么好说的事情（

14:25 芜湖考生能用windows了，zdjd
      我去真能用了[星星脸]
      不儿怎么是win7啊！！！

14:30 提取码：
      Oct31==Dec25?
	  （问号不是自己加的）
	  显然条件==false（
	  开始做题吧

14:40 贪心吗（思考）
	  不对或许是DP

15:10 原来是双指针啊

15:20 OK大样例过了奖励自己玩两把扫雷（
*/
