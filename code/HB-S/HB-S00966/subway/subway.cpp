#include<bits/stdc++.h>
using namespace std;
const int L=100010;
int w[L],g[L],x[L],y[L];
int main(){
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int bianhao,lushu,zhanshu,jinguoshu,jihuashu;
    cin>>bianhao>>lushu>>zhanshu>>jinguoshu>>jihuashu;
    for(int i=0;i<zhanshu;i++)cin>>w[i];
    for(int i=0;i<jihuashu;i++)cin>>g[i];
    for(int i=0;i<(lushu+jihuashu+2);i++)cin>>x[i]>>y[i];
    if(bianhao!=0)return 0;
    return 0;
}
