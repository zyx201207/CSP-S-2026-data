#include <bits/stdc++.h>
using namespace std;
long long n,m,b=0,c=0,d=0,e=0;
long long a[7][500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n,m;
    for (int i=1;i<=n;i++){
        cin>>a[1][i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j>=1;j++){
            if (a[1][i]<a[1][i-1]){
                e=a[1][i-1];
                a[1][i-1]=a[1][i];
                a[1][i]=e;
            }
        }
    }
    for (int i=2;i<=n;i++){
        for (int j=1;j<=i;j++){
            a[2][j]=a[1][i]-a[1][j];
        }
        for (int j=i;j>=1;j++){
            c+=a[2][j];
            if (c>m) {
                c-=a[2][j];
                b=c;
            }
        }
        if (b>d) d=b;
    }
    cout << d<<endl;
    return 0;
}
