#include <bits/stdc++.h>
using namespace std;
int a[200040];
int sv[200040];
int yu[200040];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,top=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            yu[j]=a[j];
            if(sv[a[j]]==1){
                for(int k=j;yu[k]!=a[j]||k==j;k--){
                    yu[k]=0;
                }
            }else{
              sv[a[j]]++;
            }
            for(int k=0;k<20;k++){
                cout<<a[i];
            }

        }
    }
}
