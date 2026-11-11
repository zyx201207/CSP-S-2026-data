#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],num[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[500005]={};
        for(int j=i;j<=n;j++){
            b[j]=a[j];
            num[a[j]]++;
            bool flag=0;
            for(int k=i;k<j;k++){
                if(b[k]==b[j]&&b[k]!=0){
                    flag=1;
                }
                if(flag&&b[k]!=0){
                    num[b[k]]--;
                    b[k]=0;
                }

            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
