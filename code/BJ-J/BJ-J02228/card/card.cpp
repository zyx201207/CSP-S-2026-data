#include<iostream>
using namespace std;
int a[1000009],d[1000009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int b[1000009]={},c[1000009]={},l=1;
        for(int j=i;j<=n;j++){
            if(!b[j]){
                b[j]=1;
                c[l++]=a[j];
            }
            else{
                for(int k=1;k<=j;k++){
                    if(a[k]==a[j]){
                        for(int v=k;v<j;v++){
                            c[v]=0;
                        }
                        c[l++]=a[j];
                        break;
                    }
                }
            }
        }
        for(int j=i;j<=l;j++){
            if(c[j]!=0) d[c[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++){
        if(d[i]!=0) cout<<d[i]<<" ";
    }
    return 0;
}
