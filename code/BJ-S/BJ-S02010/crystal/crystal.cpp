#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
long long d[N];
long long ans;
long long sum;
//bool cmp(long long q,long long h){
//    if()
//}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    for(int i=1;i<=n;i++){
        d[i]=sum-a[i];
    }
    sort(d+1,d+n+1);
    int i=1;
    while(m&&i<=n){
        if(m>=d[i]){
            m-=d[i];
            ans++;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
