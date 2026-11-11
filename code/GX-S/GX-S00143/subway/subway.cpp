#include<bits/stdc++.h>
using namespace std;

int m,n,d,q,C,k[550],a[500010];
int x,y,ans;
bool a1[50010][550];

struct dt{
    long long aa[50010];
}b[550];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int mm;
            cin>>mm>>b[i].aa[mm];
            a1[mm][i]=true;
        }
    }
    for(int i=1;i<q;i++){
        cin>>x>>y;
        ans+=a[x]+a[y];
        for(int i=1;i<=n;i++){
            if(a1[x][i]==true&&a1[y][i]==true){
                ans+=b[i].aa[x]+b[i].aa[y];
            }
        }
        cout<<ans<<endl;
    }

    fclose(stdin);fclose(stdout);
    return 0;
}

