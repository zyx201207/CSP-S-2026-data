#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef int I;
I m,n,v[500001],q,c,k[500001],a[500001][501],t[500001][501],sum=0,x,y,ti[500001];
I Min,Minw,p1,p2;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>n>>q;
    for(I i=1;i<=m;i++)cin>>v[i];
    for(I i=1;i<=n;i++){
        cin>>k[i];
    }
    for(I i=1;i<=n;i++){
        for(I j=1;j<=k[i];j++){
            cin>>a[i][j];
            p1=a[i][j];
            cin>>t[i][p1];
        }
    }
    cin>>q;
    for(I i=1;i<=q;i++){
        cin>>x>>y;
        sum=v[x]+v[y];
        for(I j=1;j<=n;j++){
            for(I o=1;o<=k[i];o++){
                if(a[j][m]==x){
                    for(I s=1;s<=k[i];s++){
                        p1=a[j][s];
                        p2=a[j][s+1];
                        if(t[j][p1]>t[j][p2]){
                            Min=t[j][p2];
                            Minw=p2;
                        }
                        if(t[j][p1]<t[j][p2]){
                            Min=t[j][p1];
                            Minw=p1;
                        }
                    }
                }
            }
        }

        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
