//贾启航 GZ-J00385 个人报名
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,y,a[200005]={},xy=0;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        int z;
        cin>>z;
        a[i]=z;
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y--;j++){
            if(a[i]&a[i+j]>xy){
                xy=a[i]&a[i+j];
            }
        }
    }
    cout<<xy;
    return 0;
}
