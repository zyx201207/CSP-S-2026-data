#include<bits/stdc++.h>
using namespace std;
int a[41][200010];
void twojingzhi(int x,int i,int l){
    if(x>1) twojingzhi(x/2,i,l+1);
    a[41-l][i]=x%2;
    a[41-l][0]+=(x%2);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        twojingzhi(x,i,1);
    }
    long long ans=0;
    for(int i=1;i<=40;i++){
        if(a[i][0]<m) continue;
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){
                for(int k=i;k<=40;k++){
                    a[k][0]-=a[k][j];
                    a[k][j]=0;
                }
            }
        }
        ans+=pow(2,40-i);
    }
    cout<<ans;
    return 0;
}
