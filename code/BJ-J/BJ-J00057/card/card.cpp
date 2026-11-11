#include<iostream>
using namespace std;
int n,m,a[500005],pd[5000005],p,t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=j;k++){
                if(pd[k]==a[j]){
                    for(int v=k;v<=j;v++){
                        pd[v]=0;
                        p--;
                    }
                    break;
                }
            }
            pd[++p]=a[j];
        }
        for(int j=1;j<=p;j++){
            t[pd[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
