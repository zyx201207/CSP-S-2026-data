#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x;
long long sum[7001000],a[7001000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        sum[x]++;
        if(sum[i]>0){
            a[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
