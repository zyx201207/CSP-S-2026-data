#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005];
bool c1[300005];
int main(){
    freopen("card.in","r",std);
    freopen("card.out","w",std);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int o=l
            bool z=0;
            for(int k=1;k<=l;k++){
                if(z){
                    b[k]=0;
                    continue;
                }
                if(b[k]==a[j]){
                    z=1;
                    l=k+1;
                }
            }
            b[l]=a[j];
        }
        while(l){
            if(!c1[b[l]]){
                c[b[l]]++;
                c1[b[l]]=1;
            }
            b[l]=0;
            l--;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
