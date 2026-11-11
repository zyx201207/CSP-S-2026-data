#include<bits/stdc++.h>
using namespace std;
int a[200005][35];
int f[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,t=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i][0]);
        int v=0;
        while(a[i][0]){
            a[i][++v]=a[i][0]%2;
            a[i][0]/=2;
        }
    }
    for(int i=30;i>=1;i--){
        int s=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1&&f[j]==0){
                s++;
            }
        }
        t=t*2+(s>=m);
        if(s>=m){
            for(int j=1;j<=n;j++){
                if(a[j][i]==0){
                    f[j]=1;
                }
            }
        }

    }
    cout<<t;
    return 0;
}
