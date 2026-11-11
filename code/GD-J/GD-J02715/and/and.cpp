#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100000000],b[100000000],c,sum,check=2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    c=1;
        while(a[i]>0){
            b[i]+=(a[i]%2)*c;
            a[i]/=2;
            c=c*10;
        }
    }
    sort(b+1,b+n+1);
    sort(a+1,a+n+1);
    sum=b[n]&b[n-1];
    for(int i=n-2;check<m;i--){
        sum=sum&b[i];
        check++;
    }
    cout<<sum<<endl;
    return 0;
}
