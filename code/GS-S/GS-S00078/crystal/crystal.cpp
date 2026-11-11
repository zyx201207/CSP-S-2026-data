#include<bits/stdc++.h>
using namespace std;
int n,d,cnt=1;
const int N = 5e5+10;
long long m;
long long a[N];
long long sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    d=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(sum>m){
            sum-=(i-1)*d;
            break;
        }
        if(sum=m){
            break;
        }
        sum+=i*d;
    }
    for(int i=n-1;i>=1;i--){
        sum-=(n-i)*d;
        cnt++;
        if(sum<=0) break;
    }
    cout<<cnt;
    return 0;
}
