#include <bits/stdc++.h>
using namespace std;
int a[1000],n,m,b[1000],z,x,c[100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-z;j++){
            for(int k=0;k<j-z;k++){
                if(a[j]==a[k]){
                    x=j;
                }
            }
            b[x+j]=a[j];
            z++;
        }
        z=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<n*(n-1);j++){
            if(b[j]==i){
                c[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i];
    }
    return 0;
}
