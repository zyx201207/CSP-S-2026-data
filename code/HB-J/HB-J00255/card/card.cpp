#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int tong[300005];
int len=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int t=1;t<=n;t++){
        for(int i=1;i<=m;i++)tong[i]=0;
        for(int i=t;i<=n;i++){
            tong[a[i]]=1;
        }
        for(int i=1;i<=m;i++)ans[i]+=tong[i];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
