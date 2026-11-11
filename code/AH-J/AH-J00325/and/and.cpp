#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000005],sum;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    sum=a[1];
    for(int i=2;i<=k;i++){
        sum&=a[i];
    }
    cout<<sum;
    return 0;
}

