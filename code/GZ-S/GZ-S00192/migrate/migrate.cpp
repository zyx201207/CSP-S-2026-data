//GZ-S00192 遵义市！第四！中学！ 黄文涛
//Author: ArHanXing
//Author: GPT-6.5-Utopia-吊打dario-循环推理+++-o114514
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
#define MAXN ((xll)2e6+7)
using namespace std;
int c,T;
xll n,d;
xll a[MAXN];
xll ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>T;while(T--){
        cin>>n>>d;
        ans=0;
        fri(1,n){
            cin>>a[i];
        }
        fri(1,n){
            if(a[i+2]<=a[i]+d && a[i]+d<=a[i+3] && i+2<=n && i+3<=n){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

