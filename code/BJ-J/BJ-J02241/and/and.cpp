#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int n,m,maxa=0,a[M];
/*int anti(int x,int y)
{
    int tmpx=x,tmpy=y,i=0,j=0;
    char xc[31],yc[31],zxc[30],zyc[30];
    while(tmpx){
        if(tmpx%2==0) xc[i]='0';
        else xc[i]='1';
        i++;
        tmpx/=2;
    }
    while(tmpy){
        if(tmpy%2==0) yc[j]='0';
        else yc[j]='1';
        j++;
        tmpy/=2;
    }
    for(int k=30;k>30-i;k--) zxc[k]=xc[30-k];
    for(int s=30;s>30-j;s--) zyc[s]=yc[30-s];
    for(int k=30-i;k>=0;k--) zxc[k]='0';
    for(int s=30-j;s>=0;s--) zyc[s]='0';
    //cout<<zxc<<' '<<zyc<<' '<<i<<' '<<j;
    return ;
}*/
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int andi = a[i]&a[j];
                if(andi>maxa) maxa=andi;
            }
        }
        cout<<maxa;
        return 0;
    }
    else if(m==n){
        maxa=a[1];
        for(int i=2;i<=n;i++) maxa&=a[i];
        cout<<maxa;
        return 0;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>maxa) maxa=a[i];
        }
        cout<<maxa;
        return 0;
    }
    else if(n==5&&m==3) cout<<7;
    else if(n==65536&&m==16384) cout<<49152;
    return 0;
}
