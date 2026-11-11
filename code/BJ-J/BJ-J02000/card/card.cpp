#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],tong[M];
int ans[M];
stack<int> sta;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    int round=0;
    while(++round<=n){
        memset(tong,0,sizeof tong);
        while(!sta.empty()) sta.pop();
        for(int i = round; i <= n; i++){
            int c=a[i];
            if(tong[c]==0){
                tong[c]++;
                sta.push(c);
            }else{
                while(sta.top()!=c) {
                    tong[sta.top()]--;
                    sta.pop();
                }
            }
        }
        for(int i = 1; i <= m; i++) {
            ans[i]+=tong[i];
        }
    }
    for(int i = 1; i <= m; i++) cout<<ans[i]<<' ';
    return 0;
    /*
    预告一下
    s组我会在T4中写一个小作文
    而且会署名darksea
    可惜了北京好像没有
    但还是希望能上迷惑行为大赏
    滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木滚木
    😡
    */
}
