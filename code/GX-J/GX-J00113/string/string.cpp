#include<bits/stdc++.h>
using namespace std;
int a,b[1000001],e,g=1,f=1,x;
char c[1000001],d[10000000001],n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for (int i=1;i<=a;i++){
        cin>>b[i]>>c[i];
    }
    for (int i=1;i<=a;i++){
        e=e+b[i];
        for (int j=1;j<=b[i];j++){
            d[g]=c[f];
            g=g+1;
        }
        f=f+1;
    }
    int j=e;
    if (e%2==1){
        for (int i=1;i<=(e-1)/2;i++){
            n=d[i];
            if (d[j]!=n){
                d[j]=n;
                x+=1;
                j=j-1;
            }
        }
    }
    else{
        for (int i=1;i<=e/2;i++){
            n=d[i];
            if (d[j]!=n){
                d[j]=n;
                x+=1;
                j=j-1;
            }
        }
    }
    cout<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
