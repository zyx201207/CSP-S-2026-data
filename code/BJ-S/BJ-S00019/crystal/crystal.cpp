//pls let me AC
//I really need it
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[514514],f=1,f2=1;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]!=i)f=0;
        if (i>=2&&i<n&&a[i]-a[i-1]!=a[i+1]-a[i]){
            f2=0;
        }
    }if (f==1){
        long long k=0,s=0,mx=a[1],as=0;

        for (int i=1;i<=n;i++){
            mx=max(mx,a[i]);
            s++;
            k+=a[i];
            long long t=mx*s;
            if (t-k<=m){
                as=max(as,s);
            }
        }cout<<as;
        return 0;
    }else if (f2==1){
        long long k=0,s=0,mx=a[1],as=0;

        for (int i=1;i<=n;i++){
            mx=max(mx,a[i]);
            s++;
            k+=a[i];
            long long t=mx*s;
            if (t-k<=m){
                as=max(as,s);
            }
        }cout<<as;
        return 0;
    }

    sort(a+1,a+n+1);
    long long as=0;
    for (int i=1;i<=n;i++){
        long long k=0,s=0,mx=a[i];
        for (int j=i;j<=n;j++){
            mx=max(mx,a[j]);
            s++;
            k+=a[j];
            long long t=mx*s;
            //cout<<t<<" "<<k<<"\n";
            if (t-k<=m){
                as=max(as,s);
            }
        }
    }cout<<as;
    return 0;
}
