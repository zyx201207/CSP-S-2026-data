#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005],maxn,minn=INT_MAX;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    else if(m==n){
        long long x=a[1];
        for(int i=2;i<=n;i++) x=x&a[i];
        cout<<x;
        return 0;
    }
    else if(m==2){
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                sum=max(sum,(a[i]&a[j]));
            }
        }
        cout<<sum;
        return 0;

    }
    else if(m==n-1){
        long long sum=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]!=minn){
                sum=sum&a[i];

            }
            else minn=-1;
        }
        cout<<sum;
        return 0;
    }



    return 0;
}
