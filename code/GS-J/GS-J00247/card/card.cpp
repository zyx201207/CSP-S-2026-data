#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",std::in);
    freopen("travel.out","w",std::out);
    int n,m,q;
    cin>>n>>m;
    int w[n],a[m+1];
    for(int i=0;i<n;i++)cin>>w[i];
    int ww[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            w[i][j]=0;
        }
    }
    for(int i=0;i<=m;i++){
        a[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ww[i][j]=w[j]
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int y=i;y<j;y++){
                if(ww[i][y]==ww[i][j]){
                    for(int k=y;k<j;k++)ww[i][k]=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            q=ww[i][j];
            a[q]+=1;
        }
    }
    for(int i=1;i<=m;i++)cout<<a[i]<<' ';
    return 0;
}