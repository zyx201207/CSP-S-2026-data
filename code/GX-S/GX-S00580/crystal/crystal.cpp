#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+1;
long long a[N];
int main(){


    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    long long m;
    cin>>n>>m;
    int k,kk;
    int f=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (i==2){
            k=a[i]-a[i-1];
        }
        if (i>2){
            kk=a[i]-a[i-1];
            if (kk!=k){
                f=0;
            }
        }

    }

    //cout<<"F"<<f<<endl;
    if (f==1){
        long long c=0;
        for (int i=1;i<=n;i++){

            c+=(a[i]-a[i]);
            if (c>m){
                cout<<i-1;
                return 0;


            }
        }


    }
    sort(a+1,a+n+1);

    long long maxx=0;

    long long p,t;
    for (int i=1;i<=n;i++){
        p=0;
        t=0;
        for (int j=1;j<=i-1;j++){
            p+=(a[i]-a[i-j]);
            if (p>m){
                t=j;
                break;
            }
            t=j+1;
        }
        maxx=max(maxx,t);

    }
    cout<<maxx;

    return 0;
}
