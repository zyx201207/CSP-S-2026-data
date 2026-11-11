#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    int a[500001]={};
    for(int i=1;i<=n;i++)cin>>a[i];
    int d[500001]={};
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
    int cnt=1;
    sort(d+1,d+1+n);
    while(m>0){
        m-=d[cnt++];
    }
    if(m<0) cnt--;
    cout<<cnt;
    return 0;
}
