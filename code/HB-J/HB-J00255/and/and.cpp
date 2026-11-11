#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define LL long long
LL n,a[200005],ans=((1<<31)-1);
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    for(int i=1;i<=m;i++){
            //cout<<ans<<' ';
            ans=(ans&a[i]);
    } //cout<<ans<<' ';
    cout<<ans;
    return 0;
}

