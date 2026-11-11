#include<bits/stdc++.h>
using namespace std;
int a[500005];
int c[500005];
int b[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int n2=n;
        for(int h=n;h>=i;h--){
            c[h]=a[h];
        }
        for(int h=1;h<n2;i++){
            for(int j=h+1;h<=n2;j++){
                if(c[h]==c[j]){
                    for(int k=i+1;k<=j;k++){
                        c[k]=0;
                    }
                    for(int k=j+1;k<=n2;k++){
                        c[h+k-j]=a[k];
                        c[k]=0;
                    }
                    n2=n2+h-j;
                    break;
                }
            }
        }
        for(int h=1;h<=n2;i++){
            b[i]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
