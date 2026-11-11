#include<bits/stdc++.h>
using namespace std;

#define var long long
#define ln '\n'
#define Pt(x) fixed<<setpericison(x)
#define strsiz(x) (var)(x.size())

const var MaxN=5e5+10;
var n,m;
var a[MaxN];
var dif[MaxN];
var sum[MaxN];

bool check(var t,var k){
    var sum=0;
    for(var i=1;i<=k;i++){
        var u=k+t-1;
        sum+=dif[u]*i;
    }
    return sum<=m;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(var i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    for(var i=1;i<=n-1;i++){
        dif[i]=a[i+1]-a[i];
        sum[i]=sum[i-1]+dif[i];
    }

    var ans=1,kt=0;
    for(var i=1,j=1;i<=n-1;i++){
        while(j<n-1 && kt+dif[j]*(j-i+1)<=m){
            kt+=dif[j]*(j-i+1);
            j++;
        }

        ans=max(ans,j-i+1);
        kt-=sum[j-1]-sum[i-1];
    }

    cout<<ans<<ln;
    return 0;
}
/*
g++ crystal.cpp -o crystal.exe -O2 -std=c++14
./crystal.exe < crystal1.in > crystal.out
diff crystal1.ans crystal.out
./crystal.exe < crystal2.in > crystal.out
diff crystal2.ans crystal.out
./crystal.exe < crystal3.in > crystal.out
diff crystal3.ans crystal.out
./crystal.exe < crystal4.in > crystal.out
diff crystal4.ans crystal.out

*/