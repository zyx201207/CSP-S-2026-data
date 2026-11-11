#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[500005],d[500005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,pd;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        pd=1;
        bool ctn;
        for(int pa=i;pa<=n;pa++){
                ctn=1;
            for(int j=1;j<pd;j++){
                if(d[j]==a[pa]){
                    pd=j+1;
                    ctn=0;
                    break;
                }
            }
            if(ctn){
                d[pd]=a[pa];
                pd++;
            }
        }
        for(int j=1;j<pd;j++){
            c[d[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
