//GZ-J00008
//陈申翰林
//贵阳市第三十三中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int tmp=0,maxn=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<i+m;j++){
            tmp=a[j] & a[j+1];
        }
        maxn=max(maxn,tmp);
    }
    cout<<maxn;
    return 0;
}
