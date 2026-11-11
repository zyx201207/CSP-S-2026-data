#include <bits/stdc++.h>
using namespace std;
struct cc{
    int sum;
    char leter;
};
cc a[200010],b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,h=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].sum>>a[i].leter;
        h+=a[i].sum;
        b[i].sum=a[i].sum;
        b[i].leter=a[i].leter;
    }
    for(int i=1;i<=n;i++){
        if(a[i].leter!=b[n-i+1].leter) ans+=max(a[i].sum,b[n-i+1].sum);
    }
    cout<<ans/2;
    return 0;
}
