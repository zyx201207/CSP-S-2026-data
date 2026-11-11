#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],c[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) b[j]=0;
        for(int j=i;j<=n;j++){
            bool ok=0;
            for(int k=1;k<=j-i+1;k++){
                if(b[k]==a[j]){
                    for(int l=k+1;l<=j-i+2;l++) b[l]=0;
                    ok=1;
                    break;
                }
            }
            if(ok==0) b[j]=a[j];
        }
        for(int j=1;j<=n;j++){
            c[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
    return 0;
}
