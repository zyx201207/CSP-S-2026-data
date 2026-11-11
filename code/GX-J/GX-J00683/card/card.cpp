#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n]={},sum[m]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[n]={};
        for(int j=0;j<n-i+1;j++){
            b[j]=a[j+i-1];
            for(int k=0;k<j;k++){
                if(b[k]==b[j]){
                   for(int y=k;y<j;y++){
                       b[y]=0;
                   }
                }
            }
        }
        for(int j=1;j<=m;j++){
            for(int k=0;k<n-i+1;k++){
                if(j==b[k]) sum[j-1]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
