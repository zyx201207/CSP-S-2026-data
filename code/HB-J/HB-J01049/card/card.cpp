#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector <int> a (n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector <int> c(m+1);
    for(int i=1;i<=m;i++){
        c[i]=0;
    }
    for(int i=1;i<=n;i++){
        vector <int> b(n+1);
        for(int j=i;j<=n;j++){
            b[j]=a[j]+0;
            for(int k=1;k<=j;k++){
                if(b[k]==b[j]){
                    for(int l=k;l<j;l++){
                        b[l]=-1;
                    }
                }
            }
        }
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                if(b[k]==j){
                    c[j]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout <<c[i]<<" ";
    }
    return 0;
}
