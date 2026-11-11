#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10000000],k,t,a,x,y,maxa,connect[505][505];
bool box[505][1000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            maxa=max(maxa,a);
            box[i][a]=1;
        }
    }
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int l=1;l<=maxa;l++)
                if(box[i][l]&&box[j][l])
                    connect[i][j]=1,tot++;
    while(tot<n*n)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int l=1;l<=n;l++)
                    if(connect[i][j]&&connect[j][l]&&connect[i][l]==0)
                        connect[i][l]=connect[i][j]+connect[j][l],tot++;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        int l1,l2;
        for(int j=1;j<=n;j++){
            bool flag=0;
            for(int l=1;l<=n;l++){
                if(box[j][x]&&box[l][y]){
                    flag=1,l1=j,l2=l;
                    break;
                }
            }
            if(flag)    break;
        }
        if(l1==l2)
            cout<<2*t+w[x]+w[y]<<endl;
        else
            cout<<2*t*(connect[l1][l2]+1)+w[x]+w[y]<<endl;
    }
    return 0;
}