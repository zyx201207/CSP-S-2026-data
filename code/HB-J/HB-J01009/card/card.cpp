#include <bits/stdc++.h>
using namespace std;
long long a[100001],b[100001],c[100001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,x=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<=100001;i++) c[i]=0;
    for(int l=1;l<=n;l++){
        for(long long i=1;i<=100001;i++) b[i]=0;
        for(int i=l;i<=n;i++){
            bool t=true;
            for(int j=1;j<=i;j++){
                if(b[j]==a[i]){
                    for(int k=j+1;k<=i;k++){
                        b[k]=0;
                        x--;
                    }
                }
                b[i]=a[i];
                x++;
            }
            for(int i=1;i<=x;i++) c[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
    return 0;
}
