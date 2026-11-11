#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[50],b[50],c[50];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
    cout<<n;
    }
    else if(m==2){
    b[1]=1;
    b[2]=2;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j]==1){
                if(b[1]!=1&&b[2]!=1){
                    b[2]=1;
                }
                else if(b[1]=1){
                    b[2]=0;
                    b[1]=1;
                }
                else{
                    b[2]=1;
                }
            }
            else{
                if(b[1]!=2&&b[2]!=2){
                    b[2]=2;
                }
                else if(b[1]=2){
                    b[2]=0;
                    b[1]=2;
                }
                else{
                    b[2]=2;
                }
            }
            if(j==n){
            c[b[1]]++;
            c[b[2]]++;
                }
            }
        }
        cout<<c[1]<<" "<<c[2];
    }
    return 0;
}
