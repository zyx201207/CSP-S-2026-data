#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,n;
    cin>>a>>n;
    long long b[10000];
    long long u=0;
    for (int i=0;i<a;i++){
       cin>>b[i];
    }
    for (int i=0;i<a;i++){
        for (int j=i;j<i+n-1;j++){
        long long sum=1;
            sum&=b[j];
        }
        if(sum>u){
            u=sum;
        }
    }
    cout<<u;
    return 0;
}
