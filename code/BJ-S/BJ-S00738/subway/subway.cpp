#include<iostream>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,cnt=0;
    long long a[505];
    long long o[505];
    long long r=0;
    long long b[505][505];
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    long long k;
    for(int i=0;i<n;i++){
        cin>>k;
        int e,f;
        for(int j=0;j<k;j++){
            cin>>e>>f;
            b[i][e]=f;
        }
    }
    for(int l=0;l<=q;l++){
        int x,y,z,s,p,g,h;
        cin>>x,y;
        g=x;
        h=y;
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][g]!=0){
                    z=i;
                    g=0;
                }
                if(b[i][h]!=0){
                    s=i;
                    h=0;
                }
                if(b[i][j]==b[i+1][j]){
                    p=j;
                }
            }
        }
        cnt+=b[z][x]+b[s][y]+a[x]+a[y];
        if(z==s){
            o[r]=cnt;
            r++;
        }
        else{
            cnt+=b[z][p];
            cnt+=b[s][p];
            o[r]=cnt;
            r++;
        }
        cnt=0;

    }
    for(int i=0;i<r;i++){
        cout<<o[i]<<endl;

    }
    return 0;
}