#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,i,x=0;
    long long m,sum=0,y;
    cin>>n>>m;
    for(i=0;i<n;++i) cin>>a[i];
    i=0;
    while(m>0){
        y=0;
        sort(a,a+n);
        ++a[i];
        --m;
        ++x;
        for(int j=0;j<n/2;++j){
            if(a[i]!=a[n-i-1]){
                ++y;
            }
        }
        if(y==0){
            cout<<n;
            return 0;
        }
    }
    --x;
    for(int j=0;j<=x;++j){
        if(a[j]!=a[j+1]){
            ++sum;
            break;
        }
        ++sum;
    }
    cout<<sum;
    return 0;
}
