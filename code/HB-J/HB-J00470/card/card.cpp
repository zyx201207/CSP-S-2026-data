#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n],b[n],c[m];
    for(int i=0;i<m;i++){
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int g=0;
        for(int j=i;j<n;j++){
            b[g]=a[j];
            for(int k=0;k<g;k++){
                if(b[g]==b[k]){
                    for(int p=k+1;p<=g;p++){
                        b[p]=0;
                    }
                    g=k;
                    break;
                }
            }
            g++;
        }
        for(int j=0;j<g;j++){
            c[b[j]-1]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<c[i]<<" ";
    }
}
