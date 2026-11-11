#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long int a[500000]={ };
    int sum=m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(int i=n;i>0;i--){
        if(sum%i==0&&sum/i>=a[i]){
            cout<<i;
            return 0;
        }else{
            sum-=a[i];
        }
    }
    return 0;
}
