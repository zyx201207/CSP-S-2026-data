#include<bits/stdc++.h>
using namespace std;
const int MAXN=3000005;
long long c,t;//测试点编号与测试数据组数
long long n,k;//表示城市数量和小 W 计划建造的研发基地数量
long long u[MAXN],v[MAXN];//表示第 i 条道路连接的两座城市的编号
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>u[i]>>v[i];
        cout<<endl;
    }
    return 0;
}
