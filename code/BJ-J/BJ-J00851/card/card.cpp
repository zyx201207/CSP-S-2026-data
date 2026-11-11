#include<bits/stdc++.h>
using namespace std;
int p[500005];
int da[500005][500005];
int ans[500005];
bool chong(int x,int y){
for(int i=1;i<=n;i++){
    if(da[x][i]==da[x][y]){
        return 1;
    }
}return 0;
}
void pop(int x,int y){
for(int i=1;i<=n;i++){
    da[x][i]=0;

}da[x][y]=p[y];
}
int main(){
freopen("card.in","t",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
 for(int i=1;i<=n;i++){
    cin>>p;
 }int n1=n;
 for(int i=1;i<=n;i++){
    for(int j=1;j<=n1){
        da[i][j]==p[j+i-1];
        if(chong(i,j)){
            pop(i,j);
        }
    }
    for(int j=1;j<=m;j++){
        ans[da[i][j]]++;
    }n1--;
    p[i]=0;
 }for(int i=1;i<=m;i++){
 cout<<ans[i]<<" ";
 }
return 0;
}
