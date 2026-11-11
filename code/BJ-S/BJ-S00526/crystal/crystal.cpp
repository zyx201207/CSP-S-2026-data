#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long m;
int n;
int x[100000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    sort(a+0,a+n);
    long long b=m;
    for(int i=1;i<n;i++){
        int l=0;
        for(int j=i-1;j>=0;j--)
            l=l+(a[i]-a[j]);
        if(b>=l){
            for(int j=i-1;j>=0;j--){
                if(b>=(a[i]-a[j])){
                    b=b-(a[i]-a[j]);
                    a[j]=a[i];
                }
            }
        }

    }
    for(int i=0;i<n;i++){
        x[a[i]]++;
    }
    int mx=-1;
    for(int i=0;i<10000005;i++){
        mx=max(x[i],mx);
    }
    cout<<mx;
    return 0;
}
