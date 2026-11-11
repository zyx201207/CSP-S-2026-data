#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500001];
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
    
        cout<<n;
        return 0;
    }
    bool cz[300001]={};
    int czz[300001]={};
    int que[500001],t=0;
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(cz[a[j]]==0){
                que[++t]=a[j];
                cz[a[j]]=1;
            }
            else{
                for(int k=1;k<=t;k++){
                    if(que[k]==a[j]){
                        for(int l=k+1;l<=t;l++){
                            cz[a[l]]=0;
                        }
                        t=k;
                        break;
                    }
                }
                cz[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            if(cz[i])czz[i]++;
            cz[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<czz[i]<<" ";
    }
    return 0;
}
