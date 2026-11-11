#include<bits/stdc++.h>
using namespace std;
bool siz[1000000];
bool shu[1000000][50];
int mixed(int nom,int w){
    for(int i=1;i<=49;i++){
        shu[w][i]=0;
    }
    for(int i=1;nom>0;i++){
        if(nom%2==0){
            nom/=2;
            shu[w][i]=0;
        }else{
            nom/=2;
            shu[w][i]=1;
        }
    }
    siz[w]=true;
}
int main(){
    int ans=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int kk;
        cin>>kk;
        mixed(kk,i);
    }
/*    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++)
        cout<<shu[i][j];
        cout<<endl;
    }*/
    for(int i=40;i>0;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(siz[j]==1&&shu[j][i]==1){
                sum++;
            }
        }
        if(sum>=m){
            ans+=pow(2,i-1);
            for(int j=1;j<=n;j++){
                if(!shu[j][i]){
                    siz[j]=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
