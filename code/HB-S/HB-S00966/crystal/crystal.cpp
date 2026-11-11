#include<bits/stdc++.h>
using namespace std;
long long a[10000010];
long long n,m,t,maxx;
int main(){
    //ios::sync_with_wtdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++)cin>>a[i];
    //(a[0],a[n]);
    for(long long i=0;i<n;i++){
        t=a[i];
        while(a[i]<m)a[i]++;
    }
    for(long long i=0;i<n;i++){
        if(a[i]>a[i+1])a[i]--;
    }
    for(long long i=0;i<n;i++){
        if(a[i]==a[i+1])maxx++;
    }
    cout<<maxx++;
    return 0;
}
