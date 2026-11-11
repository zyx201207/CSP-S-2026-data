#include <iostream>
#include <cstdio>
using namespace std;
long long n,m,a[500005],k[500005],more,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i-1]==a[i]||a[i+1]==a[i]) more=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(a[i]<more){
            cnt++;
            m-=(more-a[i]);
        }
    }
    cout<<cnt;
    return 0;
}