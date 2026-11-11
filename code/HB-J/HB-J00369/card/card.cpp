#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b[500005]={},bi=1;
    int c[500005]={};
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof b);
        for(int j=i;j<=n;j++){
            if(find(b+1,b+n+1,a[j])){
                b[bi]=a[j];
                bi++;
            }
            else{
                int k=1;
                for(;k<bi;k++){
                    if(b[k]==a[j]){
                        k++;
                        break;
                    }
                }
                bi=k;
                for(;k<=n;k++)b[k]=0;
                b[bi]=a[j];
            }
            for(int l=1;l<=n;l++)c[b[l]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<c[m]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
