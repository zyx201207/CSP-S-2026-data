#include <bits/stdc++.h>
using namespace std;
int d[1000005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
int a[m+5];
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){//开始玩游戏
    int q[m+5]={0};//桌面
    for(int j=i;j<=n;j++){//第i局出牌
        q[j]+=a[j];//出牌
            int p=0;//是否有
            for(int s=i;s<j;s++){//寻找
                if(a[s]==a[j])//找到
                    p=1;//有
                if(p==1){//现在有
                    q[s]=0;//消除
                }
            }
    }

    for(int j=1;j<=n;j++){//统计
        if(q[j]>0)//如果有这个牌
            d[q[j]]++;//记录
    }
}
for(int i=1;i<=m;i++){
    cout<<d[i]<<" ";
}
return 0;

}
