#include<bits/stdc++.h>
using namespace std;
int a[500005];
int u[5005][5005];
int n,m,anso,sum,anst;
int x;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
anst=m+1;
for(int i=1;i<=n;i++){
    cin>>a[i];
    u[0][i]=a[i];
    u[i][0]=a[i];
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        u[i][j]=a[j]-a[i];
        if(j<i){
            u[i][j]=0;
        }
    }
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
           if(u[j][i]<=m-sum){
                sum+=u[j][i];
                anso++;
           }
    }
    if((sum<=m)&&(anso<anst)){
        anst=anso;
    }
    sum=0;
    anso=1;
}

if(anst==m+1){
    cout<<"1";
}else{
    cout<<anst;
}
return 0;
}
