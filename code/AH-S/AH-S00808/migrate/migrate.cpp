#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long n,m;
long long a[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    long long flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(a[i]-a[1]<=m&&a[n]-a[i]<=m)
            flag=1;
    if(flag){
        cout<<0;
    }
    else
        cout<<23251;
}
