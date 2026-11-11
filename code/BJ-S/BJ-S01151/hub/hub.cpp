#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long hzh[500010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>a[i+1];
        for(int j=1;j<=a[i];j++){
            cin>>hzh[i%500000]>>hzh[i%500000];
        }
        cout<<hzh[a[i]]+hzh[m];
    }
    return 0;
}
