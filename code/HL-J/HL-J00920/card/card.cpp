#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    long long n,m;
    cin>>n>>m;
    long long a[n]={0};
    long long b[n]={0};
    long long c[m]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            b[j]=a[j];
            for(int k=i;k<j;k++){
                if(b[k]==b[j]){
                    for(int l=i;l<j;l++){
                        b[l]=0;
                    }
                }
            }
        }
        for(int j=1;j<=m;j++){
            for(int k=0;k<n;k++){
                if(b[k]==j){
                    c[j-1]++;
                    b[k]=0;
                }
            }
        }

    }
    for(int i=0;i<m;i++){
        cout<<c[i]<<' ';
    }
    return(0);

    fclose(stdin);
    fclose(stdout);
}
