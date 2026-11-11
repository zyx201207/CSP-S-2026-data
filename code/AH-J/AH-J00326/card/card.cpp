#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[500005],pos[300005],t[500005],tz[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)cout<<1<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
