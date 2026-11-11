#include <bits/stdc++.h>
using namespace std;
int  c,n,m,d,q;
int a[500][500005]={0};
struct kv{
int o;
int g;
};
int zd(int l,int r){
    int h=l;
    int y[1005];
    for(int i=1;i<=n;i++){
        kv x[1005];
        int f=0;
        for(int j=1;j<=m && j!=h;j++){
           if(a[i][j]!=0){
                a[i][j]+=a[i][h];
            if(a[i-1][j]!=0){
                x[j].g=a[i-1][j]+a[i][j];
                x[j].o=j;
                f++;
            }
        }
    }
    sort(x,x+f);
    h=x[0].o;
    y[i]=x[r];
}
sort(y,y+n);
return y[0];}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    int w[500005];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int s;
        cin>>s;
        for(int j=0;j<s;j++){
            int a,t;
            cin>>a>>t;
            a[a][i]=t;
        }
    }
    int l[100000],r[100000];
    for(int i=1;i<=q;i++){
        cin>>r[i]>>l[i];
    }
    for(int i=1;i<=q;i++){
        cout<<zd(l[i],r[i])+w[r[i]]+w[l[i]];
    }
    fclose(stdin);
    fclose(stdout);
return 0;}
