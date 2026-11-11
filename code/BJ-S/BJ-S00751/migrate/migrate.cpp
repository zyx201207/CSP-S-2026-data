#include<iostream>
#include<cstring>
using namespace std;
long long r[10010][10010],d[10010][10010],n,m,a[10010],ans,c,t;
int main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(r,0,sizeof(r)),memset(d,0x3f3f3f3f,sizeof(d));
        for(int i=1;i<=n;i++) r[i][i]=1,d[i][i]=0;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[j]-a[i]<=m) r[i][j]=r[j][i]=1,d[i][j]=d[j][i]=1;
        for(int l=3;l<=n;l++) for(int i=1,j=l;j<=n;i++,j++) for(int k=i+1;k<j;k++) {
            if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j],r[i][j]=1;
            else if(d[i][k]+d[k][j]==d[i][j]) r[i][j]+=(r[i][k]*r[k][j]);
        }for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(r[i][j]==2) ans++;
        cout<<ans<<endl;
    }return 0;
}
