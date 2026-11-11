//GZ-S00192 遵义市！第四！中学！ 黄文涛
//Author: ArHanXing
//Author: DeepSeek v114514-pro-1331 两文风超级无敌propro吊打fable；钱版本输入 eps/Mtok 输出 eps/Mtok 缓存读取 0/Mtok
#include<bits/stdc++.h>
#define fri(a,b) for(int i=(a);i<=(b);i++)
#define frm(a,b,m) for(int m=(a);m<=(b);m++)
#define frir(a,b) for(int i=(a);i>=(b);i--)
#define frmr(a,b,m) for(int m=(a);m>=(b);m--)
#define us unsigned
#define xll signed long long
#define ull us long long
#define inf ((int)__INT_MAX__)
#define nul -inf
#define gmax(a,b) a=max(a,b)
#define gmin(a,b) a=min(a,b)
#define MAXN ((xll)5e5+7)
using namespace std;
/*

还是没有拿到一个vscode环境，悲伤了。

t1 竟然是 大音晶！！！
x x xxx

进行无数次 +1 操作，求出他最多能用多少颗能量水晶和从一个大音晶
n 5e5，考虑排序

首先目标能量肯定在所有的水晶中出现过
我们考虑离散化之后枚举目标能量，在O(1~log n)时间内得出这时可以有多少个水晶参与合成

1 2 4 8 9
假设目标是4，那么可以参与的包括 1 和 2
前缀和 3，目标值 8，差 5
m >= 5，直接过

那么呢
-3 -1 2 2 7
枚举所有值作为target的时候的需要的数量不就行了吗

xll只能存下1e18，很难全部摆正


---
没有必要在枚举这一棵树上吊死
枚举法：
1. 生成反数组及其后缀和
2. 根据目前的target，修改反数组的后缀和
3. 在上面进行二分搜索

修改后缀和是不可行的。

双指针？
维护窗口右侧最大值和区间最小值，右移右指针开销显然可以计算，右移左指针的开销也可以计算，维护顶满全部区间的开销

好像会了，非常感动，14:31


这是 GregTech Leisure 的最后一个官方版本号，虽然我是区，才想出来
*/
xll n,m;
xll a[MAXN];
xll L,R;
xll ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    fri(1,n) cin>>a[i];
    sort(a+1,a+n+1);

    xll cursum=0,curneed=0;
    L=1,R=1;
    ans=1;//when L=R=1
    while(R<=n){
        R++;
        auto tar=a[R];
        //cursum+=tar;
        curneed+=(R-L)*(a[R]-a[R-1]);
        while(curneed>m){
            //shrink L
            //cursum-=a[L];
            curneed-=(tar-a[L]);
            L++;
        }
        gmax(ans, R-L+1);

        //cout<<"--DEBUG-- "<<L<<" "<<R<<" ans = "<<(R-L+1)<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
