#include<bits/stdc++.h>
using namespace std;
const int N=500050;
long long m,ans=0;
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long a[N];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    long long c=a[n-1]-a[n-2],d;
    for(int i=1;i<=n;i++){
        m-=d;
        if(m<0){
            break;
        }
        d+=c;
        ans++;
    }
    cout<<ans;
    return 0;
}
