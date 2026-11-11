#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[999999],z[999999],l=0,f=1;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    while(n!=0){
        for (int i=0;i<n&&z[i]!=-1;i++){
            z[l]=a[i];
            for (int j=0;j<l;j++){
                if (z[j]==z[l]){
                    for (int k=0;k<j;k++){
                        z[k]=-1;
                    }
                    z[999999]={};
                    l=0;
                    break;
                }
            }
        }
        for (int i=0;i<n;i++){
            if (z[i]!=-1){
                f=0;
            }
        }
        if (f==1){
            n=0;
        }else{
            f=1;
        }
    }
    for (int i=0;i<l;i++){
        cout<<z[i]<<" ";
    }
    return 0;
}

