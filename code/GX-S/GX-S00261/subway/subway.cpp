#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001],b[500001];
int sum,h=1;
int sum1;
int sum2;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum=n/2;
    for(int i=1;i<=n;i++){
        if(a[sum]-a[i]>0){
            b[i]=a[sum]-a[i];
        }else{
            b[i]=(a[sum]-a[i])*-1;
        }
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        sum1+=b[i];
        if(sum1<=m){
            sum2++;
        }
    }
    cout<<sum2;
    return 0;
}
