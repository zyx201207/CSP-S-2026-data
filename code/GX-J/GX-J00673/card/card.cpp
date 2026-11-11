#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1005];
    int t[1005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int a1[1005];
        int x=0;
        for(int j=i-1;j<n;j++){
            for(int k=0;k<x;k++){
                if(a[j]==a1[k]){
                    for(int y=0;y<x;y++){
                        a1[y]=0;
                    }
                    x=0;
                }
            }
            a1[x]=a[j];
            x++;
        }
        for(int r=1;r<=m;r++){
            for(int e=0;e<x;e++){
                if(a1[e]==r){
                    t[r-1]++;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
