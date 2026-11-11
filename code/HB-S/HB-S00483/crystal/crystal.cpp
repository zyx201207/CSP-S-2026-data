#include<bits/stdc++.h>
using namespace std;
         // 1234567
long long a[500005];
long long b[100000005];


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    long long n,m,sum = 0,ma,mi;
    cin>>n>>m;

    for(long long i = 1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }

    sort(a+1,a+n+1);

    ma = a[n];
    mi = a[1];


    for(long long i = mi;i<=ma;i++){
        sum = max(b[i],sum);
    }

    cout<<sum+2;




    return 0;
}
