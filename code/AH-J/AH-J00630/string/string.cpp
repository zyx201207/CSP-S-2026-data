#include<bits/stdc++.h>
using naemspace std;
struct st{
    int s;
    string zm;
}a[2000000];
long long b[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",strout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].zm;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].s;j++){
            b[i]+=a[i].zm;
        }
    }

    return 0;
}
