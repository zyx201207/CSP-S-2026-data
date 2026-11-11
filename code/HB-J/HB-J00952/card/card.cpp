#include<bits/stdc++.h>
using namespace std;
int a[500009],b[300007],y[500007],num[300007];//a in b dui x y out
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++){
    int z=1;
    for(int j=i;j<=n;j++){
        if(b[a[j]]==0){
            b[a[j]]=z;
            y[z]=a[j];
            num[y[z]]++;
            z++;
        }
        else{
        int p=z;
        for(int k=b[a[j]];k<=p;k++){
            num[y[k]]--;
            y[k]=0;
            z--;
            }
            y[z]=a[j];
            z++;
            num[y[z-1]]++;
        }
    }
    for(int x=0;x<=n;x++){
        b[x]=0;y[x]=0;
    }
}
for(int i=1;i<=m;i++)cout<<num[i]<<" ";
return 0;
}
