#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a[10000000];
    for(int i=1 i<=n;i++){
        cin>>a[i];
    }
    long long b[100000000][100000000];
    long long m;
    cin>>m;
    for(int i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){

            b[j]=a[j];
            for(int j=1;j<i;j++){
                if(b[j]==b[i]){
                    for(int k=1;k<j;k++){
                            if(b[i][k]==b[j]){
                                for(int l=j;l<n;l++){
                                    b[i][l]=b[i][l+1];
                                }

                            }

                    }
                }

            }
        }
    }










    return 0;

}
