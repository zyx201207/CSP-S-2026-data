#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],t;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];

    }

    else if(m==n){
        t=a[0];
        for(int i=1;i<n;i++){
            t=t&a[i];
        }
        cout<<t;
    }
    else{
        int c,d,m=0,t1;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                t1=a[i]&a[j];
                m=max(t1,m);
            }
        }
        cout<<m;
    }
    return 0;
}
