#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("subway.in";"r";stdin);
    //freopen("subway.out";"w";stdout);
    int c;
    cin>>c;
    int n,m;
    cin>>n>>m;
    int d,q;
    cin>>d>>q;
    int w[m+1];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int a[n+1][m+1];
    int t[n+1][m+1];
    int k[n+1];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2k[i];j+=2){
            cin>>a[i][j];
            cin>>t[i][j+1];
        }
    }
    int x[q+1];
    int y[q+1];
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++){
        int ti=w[x[i]]+w[y[i]];
        int ans=
        int r=x[i];
        while(r!=y[i]){
            for(int j=1;j<=n;j++){
                for(int l=1;l<=k[j];l++){
                    if(r=a[j][l]){
                        ti+=t[i][l]+t[j][k[j]+1-l];
                        r=a[j][k[j]-l+1];
                        a[j][k[j]-l+1]=0;
                    }
                }
            }
        }
        cout<<ti<<endl;
    }
    return 0;
}