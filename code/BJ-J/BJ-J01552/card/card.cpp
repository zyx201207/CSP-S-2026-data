#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500000]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=1;
    int b[500000]={},c[300000]={},cc[300000]={};
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            if(c[a[cnt]]==0){
                b[cnt]=a[i];
                c[a[i]]=cnt;
            }else{
                cnt=c[a[cnt]];
            }
            cnt++;
        }
        for(int i=j;i<=n;i++){
            cc[a[i]]++;
        }
        for(int i=j;i<=n;i++){
            cout<<cc[a[i]];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
