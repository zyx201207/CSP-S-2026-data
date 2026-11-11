#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,d,q,k[5005];
bool a[5005][5005];
int t[5005][5005];
ll n,m,w[5005];
ll s[505][505];
void floyd(){
    for(int k=1;k<=m;++k){
        for(int i=1;i<=m;++i){
            if(i==k) continue;
            for(int j=1;j<=m;++j){
                if(j==i||j==k) continue;
                if(s[i][k]!=-1&&s[k][j]!=-1){
                    if(s[i][k]+s[k][j]<s[i][j]){
                        s[i][j]=s[i][k]+s[k][j]+1;
                    }
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int T;
    bool B=(c>=12&&c<=19);
    if(B){
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                int x;
                cin>>x>>T;
                a[i][x]=1;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                int x;
                cin>>x>>t[i][j];
                a[i][x]=1;
            }
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            s[i][j]=s[j][i]=-1;
            for(int l=1;l<=n;l++){
                if(a[l][i]&&a[l][j]){
                    s[i][j]=s[j][i]=0;
                    break;
                }
            }
            if(s[i][j]==0) continue;
            for(int l=1;l<=n;l++){
                if(s[i][j]==1) break;
                for(int r=l+1;r<=n;r++){
                    if(a[l][i]&&a[r][j]){
                        s[i][j]=s[j][i]=1;
                        break;
                    }
                }
            }
        }
    }
    floyd();
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        //if(B){
            cout<<w[x]+w[y]+s[x][y]*T;
        //}
    }
    return 0;
}
