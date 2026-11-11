//GZ-J00008
//陈申翰林
//贵阳市第三十三中学
#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,a[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        cout<<x<<" ";
        x++;
    }
    return 0;
}
