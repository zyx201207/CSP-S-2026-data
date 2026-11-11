#include<bits/stdc++.h>

using namespace std;

int n,m,g;

long long ans;

int main(){

    freopen("and.in","r",stdin);

    freopen("and.out","w",stdout);

    cin>>n>>m;

    long long ci,a[n];

    for(int i=0;i<n;i++){

        cin>>a[i];

    }

    if(m==1){

        long long  d=-1;

        for(int i=0;i<n;i++){

            d=max(d,a[i]);

        }

        cout<<d;

        return 0;

    }else if(m==n){

        ans=a[0];

        for(int i=1;i<n;i++){

            ans=ans&a[i];

        }

        cout<<ans;

    }else{

        sort(a,a+n);

        cout<<a[n-m];

    }

    return 0;

}
