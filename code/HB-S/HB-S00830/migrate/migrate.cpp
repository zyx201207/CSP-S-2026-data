#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
long long c,t,n,d;//测试点编号与测试数据组数,岛屿数量和海鸟一次最多能飞行的距离
long long x[MAXN];//每座岛屿的坐标
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    return 0;
}
