#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            b[j]=a[i+j];
            for(int k=0;k<j;k++){
                if(b[k]==b[j]){
                    for(int l=k+1;l<=j;l++){
                        b[l]=0;
                    }
                }
            }
        }
        for(int j=0;j<n-i;j++){
            if(b[j]!=0){
                c[b[j]]++;
                b[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(c[i]!=0){
            cout<<c[i]<<' ';
        }
    }
    return 0;
}
