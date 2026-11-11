/*#include<bits/stdc++.h>
using namespace std;
const int maxm=2e4+5;
int c,n,m,d,q,w[maxm],k[505];
int a[505][maxm],t[505][maxm];
int x,y,sum=0,ans=maxm*505;
bool flag[maxm]={true},s[maxm][505];
void dfs(int d){
    if(sum>=ans)return;
    if(d==y){
        ans=sum;
        return;
    }
    for(int i=1;i<=n;i++){
        if(s[d][i]){
            for(int j=1;j<=k[i];j++){
                if(flag[j]){
                    flag[j]=false;
                    sum=sum+t[i][d]+t[i][j];
                    dfs(j);
                    flag[j]=true;
                    sum=sum-t[i][d]-t[i][j];
                }
            }
        }
    }
}
int main(){
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i]/2;j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            s[a[i][j]][i]=true;
        }
    }
    while(q--){
        cin>>x>>y;
        if(x==y){
            cout<<0<<endl;
            return 0;
        }
        sum=w[x]+w[y];
        dfs(x);
        cout<<ans<<endl;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5;
int c,n,m,d,q,w[maxm],k[505];
int a[505][maxm],t[505][maxm];
int x,y,sum=0,ans=maxm*505;
bool flag[maxm];
int isontrip(int x,int y){
    for(int i=1;i<=m;i++){
        if(a[x][i]==y)return i;
    }
    return 0;
}
void dfs(int d){
//    cout<<"nowd="<<d<<endl;
    if(sum>=ans)return;
    if(d==y){
        ans=sum;
//        cout<<"lastsum="<<sum<<endl;
        return;
    }
//    cout<<"next station...\n";
    for(int i=1;i<=n;i++){
        int eng=isontrip(i,d);
        if(eng){
            sum+=t[i][eng];
//            cout<<"get on "<<i<<"line at "<<d<<" station and nowsum="<<sum<<endl;
            for(int j=1;j<=m;j++){
//                cout<<"flagj="<<(int)flag[j]<<",j="<<j<<",isontrip="<<(int)isontrip(i,j)<<endl;
                int neg=isontrip(i,j);
                if(flag[j]&&neg){
                    flag[j]=false;
                    sum+=t[i][neg];
//                    cout<<"leave at "<<j<<" station and nowsum="<<sum<<endl;
                    dfs(j);
//                    cout<<"back from "<<j<<" station\n";
                    flag[j]=true;
                    sum-=t[i][neg];
                }
            }
            sum-=t[i][eng];
//            cout<<"tuipiao for "<<i<<"line at "<<d<<" station and nowsum="<<sum<<endl;
        }
    }
    return;
}
int main(){
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
//        cout<<w[i]<<",";
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
    }
//    for(int i=1;i<=n;i++){
//        cout<<k[i]<<"* ";
//        for(int j=1;j<=k[i];j++)cout<<a[i][j]<<"& "<<t[i][j]<<"% ";
//    }
    while(q--){
        memset(flag,true,sizeof(flag));
        cin>>x>>y;
        if(x==y){
            cout<<0<<endl;
            return 0;
        }
        sum=w[x]+w[y];
//        cout<<"why x="<<x<<endl;
        flag[x]=false;
        dfs(x);
        cout<<ans<<endl;
    }
    return 0;
}
