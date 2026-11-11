#include<bits/stdc++.h>
#define mian main
using namespace std;
int mian(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    unsigned long long a[100001]={1},ans=18446744073709551615;
    //cout<<(10100&10010); 按位与
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    long long j=n;
    for(int i=1;i<=m;i++){
        //cout<<a[j]<<' ';
        ans=ans&a[j];
        //cout<<ans<<' ';
        j--;
    }
    cout<<ans;
    return 0;
}
/*  
*/