#include<bits/stdc++.h>
using namespace std;
long long a[2000010],n,d;
long long way_(long long x1 , long long x2 , long long sum){
    long long ans = 0;
    if(x1==x2){
        ans = min(ans,sum);
    }
    for(long long i = 1 ; i <= d ; i++){
        way_(x1+i,x2,sum+1);
    }
    return ans;
}
long long su_(long long x1,long long x2,long long sum,long long ans){
    long long aans = 0;
    if(x1==x2){
        if(sum == ans) aans++;
    }
    for(long long i = 1 ; i <= d ; i++){
        way_(x1+i,x2,sum+1);
    }
    return aans;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,sum = 0;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(long long i = 1 ; i <= n ; i++){
            cin >> a[i];
        }
        for(long long i = 1 ; i <= n-2 ; i++){
            for(long long j = i+2 ; j <= i ; j++){
                if(su_(a[i],a[j],0,way_(a[j],a[i],0))==2){
                    sum++;
                }
            }
        }
        cout << sum;
        sum = 0;
}
    return 0;
}
