#include<bits/stdc++.h>
using namespace std;
int n,m,a1[5020],a2[5020],ans,i=1,b[3050];
void gai(){
    for(int ii=1;ii<i;ii++){
        if(a2[ii]==a2[i-1]){
            for(int j=ii;j<i-1;j++){
                    a2[j]=0;
            }
        }
        a2[ii]=a2[i-1];
        break;
    }
    return ;
}
void g(){
    for(int j=1;j<=m;j++){
        for(int k=1;k<i;k++){
            if(a2[k]==j){
                b[j]+=1;
                break;
            }
        }
    }
    return ;
}
void qing(){
    for(int j=1;j<i;j++){
        a2[j]=0;
    }
    return ;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int j=1;j<=n;j++){
        cin>>a1[j];
    }
    for(int j=1;j<=n;j++){
        qing();
        i=1;
        for(int k=j;k<=n;k++){
            a2[i]=a1[k];
            gai();
            i++;
        }
        g();
    }
    for(int j=1;j<=m;j++){
        cout<<b[j]<<" ";
    }
    return 0;
}
