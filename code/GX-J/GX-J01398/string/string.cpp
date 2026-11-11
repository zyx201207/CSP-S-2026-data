#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a[1000001][1000001]={0};
    int n,c=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(a[j]==a[j+1]){
                c=0;
            }
        }
    }
    if(n%2!=0){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=n;k>=0;k--){
                    if(a[i][j]==a[n-i][k]){
                        c=0;
                    }
                }
            }
        }
    }
    if(n%2==0){
               for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=n;k>=0;k--){
                    if(a[i][j]==a[n-i][k]){
                        c=0;
                    }
                }
            }
        }
    } else {
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(a[i][j]!=a[n-i][n-j]){
                    c++;
                }
            }
        }
    }
    cout<<c;
    return 0;
}
