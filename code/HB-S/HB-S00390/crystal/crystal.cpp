#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long b[2][n*n/2+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long t=2,sum=0;
    while(t<=n){
        for(int i=1;i<=n-t+1;i++){
            sum++;
            b[1][sum]=t;
            for(int j=i;j<=i+t-2;j++){
                b[2][sum]+=a[i+t-1]-a[j];
            }
        }
        t++;
    }
    long long max_n=0;
    for(int i=1;i<=sum;i++){
        if(b[1][i]>max_n && b[2][i]<=m) max_n=b[1][i];
    }
    cout<<max_n;
    return 0;
}
