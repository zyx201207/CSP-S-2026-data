#include<bits/stdc++.h>
using namespace std;

long long n,a[500005],maxx,m,len=1;
unsigned long long dqq;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        dqq+=(a[i+1]-a[i])*len;
        len++;
        while(dqq>m){
            len--;
            dqq-=a[i+1]-a[i+1-len];
        }
        maxx=max(len,maxx);
    }
    cout<<maxx;

    return 0;

}
