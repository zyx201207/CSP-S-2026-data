#include<bits/stdc++.h>
using namespace std;
int m,n;
long long s,a[20005],x,maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i= 1;i<=n;i++){
        cin>>a[i];
        s=max(s,a[i]);
    }
    if(m==2){
        for(int i = 1;i<n;i++){
            for(int j = i+1;j<=n;j++){
                x=a[i]&a[j];
                maxn=max(maxn,x);
            }
        }
    }
    if(m==1)maxn=s;
    if(m==n-1){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(j==i)continue;
                x=x&a[j];
            }
            maxn=max(maxn,x);
        }
    }
    if(m==n){
        for(int i = 1;i<=n;i++){
            maxn=maxn&a[i];
        }
    }
    cout<<maxn;
    return 0;
}


