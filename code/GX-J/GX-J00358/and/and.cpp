#include<bits/stdc++.h>
using namespace std;
long long a[40][200010],n,m,te=0,tb[40]={1},tc[40];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[1][i];
        if(m==1&a[1][i]>te) te=a[1][i];
        for(int j=1;j<=35;j++){
            if(a[j][i]>=2){
                a[j+1][i]+=a[j][i]/2;
                a[j][i]%=2;
            }
            else break;
        }
        if(m==n){
            for(int j=1;j<=35;j++) if(a[j][i]!=tb[j]) tb[j]=0;
            for(int j=35;j>1;j--)
            if(tb[j]>=1){
                tb[j-1]+=tb[j]*2;
                tb[j]=0;
            }
        }
    }
    if(m==1){
        cout<<te;
        return 0;
    }
    else if(m==n){
        cout<<tb[1];
        return 0;
    }
    else if(m==2){
        long long tcx=0;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=35;k++){
                    if(a[k][i]!=a[k][j]||(a[k][i]==0&&a[k][j]==0)) tc[k]=0;
                    else tc[k]=1;
                }
                for(int k=35;k>1;k--)
                if(tc[k]>=1){
                    tc[k-1]+=tc[k]*2;
                    tc[k]=0;
                }
                if(tcx<tc[1]) tcx=tc[1];
            }
        }
        cout<<tcx;
        return 0;
    }
    return 0;
}
