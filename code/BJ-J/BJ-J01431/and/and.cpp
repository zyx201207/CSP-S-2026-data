#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
int a[200010][33],b[200010],c[200010],nca[40];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        c[i]=b[i];
    }
    for(int i=0;i<n;i++){
        int nuc=0;
        while(b[i]>0){
            bool now=b[i]&1;
            nca[nuc]+=now;
            a[i][nuc++]=now;
            b[i]>>=1;
        }
    }
    int ptt=-1;//!!!very important!!!
    for(int i=40;i>=0;i--){
        if(nca[i]>=m){
            ptt=i;
            break;
        }
    }
    if(ptt==-1){
        cout<<0;//你什么也保护不了！
        return;
    }
    int ans=-1;
    for(int i=n-1;i>=0&&m>0;i--){
        if(a[i][ptt]==1){
            if(ans==-1){
                ans=c[i];
            }
            else{
                ans&=c[i];
            }
            m--;
            //cout<<ans<<endl;
        }
    }
    cout<<ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    //freopen("and3.in","r",stdin);
    //freopen("and.out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)solve();
}
/*
上辈子四在了T3
这辈子定要一学前吃
and越and越小
这次比赛有点纯良
我悔说这句话
T3阴爆了
考虑dp?
尝试用n^2吃分
nonono转移方程还是太难想了这辈子也不会打dp的
🤪
考虑找到最好的当底座可以吗
没事还有三个小时可以浪去看看T4
T4炸了
111010
110001
011111
010110
如果某一位上的1少于m个那么这位就保不住了
尽可能保住高位，一定不劣
ptt:protect最高的数位
-0.01
track lost
卡车丢失

wocv
我好像过了
10:13 300pts
我完了
这题如果只保护一个不是最优解
必须在保护对象中继续向下找
继续保护
而这个只能保护保护对象最大的m个
而我在最后15min才发现
我完了
fAKe
这题做法应该没有fAKe吧✖✖✖✖✖✖✖✖✖✖✖✖✖✖✖✖
希望如此给的数据不要waterful✖✖✖✖✖✖
测的数据一定要verywaterful求求了求求了求求了求求了求求了求求了求求了求求了求求了
*/
