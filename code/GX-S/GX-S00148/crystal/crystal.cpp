#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.in","w",stdout);
    long long n,m,a[500005],b[500005],l,num=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if(a[j]>a[j+1]){
                l=a[j+1];
                a[j+1]=a[j];
                a[j]=l;
            }
        }
    }

    for (int i=2;i<=n+1;i++){
        b[i-1]=a[i];
    }
    for (int i=1;i<=n;i++){
    }



    for (int i=n;i>=1;i--){
        for (int j=1;j<=i+1;j++){
            num+=b[i]-b[j];
        }
        if (num<m && b[2]-b[1]<m){
            cout<<i;
            break;
        }
        num=0;
    }
    if (b[2]-b[1]>m){
        cout<<0;
    }
    return 0;
}



