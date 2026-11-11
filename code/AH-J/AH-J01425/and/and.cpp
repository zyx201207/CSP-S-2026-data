#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    int n,m,zd=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>a[i][j];
    }
}
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((a[i][j]<a[i+1][j+1])&&n-i!=0)
                    zd=a[[i+1][j+1];
            }

        }
        cout<<zd(2);
        freopen("and.in","r",stdin);
        freopen("and.out","w",stdout);
        return 0;
}


