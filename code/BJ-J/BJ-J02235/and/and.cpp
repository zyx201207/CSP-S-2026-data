#include<bits/stdc++.h>
using namespace std;
int const N=500005;
int a[N][35];
int vis[N][35];
int b[35];
void w(int x,int y){
    int p=1;
    while(x!=0){
        if(x%2==0){
            a[y][p]=1;
            p+=1;
            x/=2;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            int z;
        cin>>z;
        w(z,i);
    }
    int o=0,r=1;
    for(int i=35;i>=1;i--){
            int sum=0;
        for(int j=1;j<=n;j++){
            if(o==0){
                vis[j][i]=0;
            }
            if(a[j][i]==1){
                    if(o==0){
                        vis[j][i]=1;
                    }
                sum+=1;
            }
        }
    if(sum>=m){
        b[r]=1;
        o=1;
    }
    r+=1;
    }
    o=0;
    r=1;
    for(int i=1;i<=r;i++){
        if(b[i]==1){
            o+=r;
        }
        r*=2;
    }
    cout<<o;
return 0;
}
