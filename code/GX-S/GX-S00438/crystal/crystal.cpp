#include <bits/stdc++.h>
using namespace std;
const long long MAXN=2e5+8;
long long  a[MAXN],b[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    int cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)b[i]=a[i]-a[i+1];
    for(int i=1;i<=n;i++){
        if(b[i]<0)b[i]*=-1;
    }
    for(int i=1;i<n;i++){
        if(b[i]==b[i+1])continue;
        if(b[i]<b[i+1])cnt+=b[i+1]-b[i];
        if(b[i]>b[i+1]){
            if(b[i]-b[i+1]>b[i]-b[i+2]){
                cnt+=b[i]-b[i+1];
            }
        }
    }

    cout<<cnt;
    return 0;
}
