#include<bits/stdc++.h>
using namespace std;
long long shulie[10000005];
long long sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,num;
    cin >> n >> num;
    if(n==num){
        cin >> sum;
        for(long long i=2;i<=n;i++){
                long long  x;
            cin >> x;
            sum=sum&x;
        }
        cout << sum;
        return 0;
    }else if(num==1){
        for(long long i=1;i<=n;i++){
                long long x;
            cin >> x;
            sum=max(sum,x);
        }
        cout<<sum;
    }else if(num==2){
        for(long long i=1;i<=n;i++){
            cin >> shulie[i];
        }
    for(long long i=1;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            sum=max(sum,shulie[i]&shulie[j]);
        }
    }
    cout << sum;
    }
    return 0;
}
