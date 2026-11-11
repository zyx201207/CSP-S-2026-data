#include<bits/stdc++.h>
#define int long long
using namespace std;
int f=0;
int a[10000001];
int b[10001][10001];
int d[10001][10001];
        int s=0;
            int m,n;
int ff(int x,int y){
    if(x==y) return 0;
    if(x==y-1)return 0;
    for(int i=x;i<=y-1;i++){
        for(int j=i+1;j<=y;j++){
            for(int h=1;h<y-x;h++){
            ff(i,j-h);
            ff(j-h,j);
            int jj=b[i][j];
            if(b[i][j-h]+b[j-h][j]==jj) d[i][j]++;
            else d[i][j]=1;
            b[i][j]=min(b[i][j],b[i][j-h]+b[j-h][j]);
            }
        }
    }
    return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,k;
    cin>>t>>k;
    if(t==11||t==12){
        for(int c=1;c<=k;c++){
            int m,n;
            cin>>n>>m;
            fill(a,a+1+n,0);
            for(int i=1;i<=n;i++)
                cin>>a[i];
            if((a[2]-a[1])*2>m){
                cout<<n<<" ";
            continue;}
        else {
            int g=m/(a[2]-a[1]);
            cout<<n-2*g+1<<" ";
        }
        }
        return 0;
    }
    if(t==13||t==14){
        for(int c=1;c<=k;c++){
            int m,n;
            int s=0;
            cin>>n>>m;
            fill(a,a+1+n,0);
            for(int i=1;i<=n;i++)
                cin>>a[i];
    for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                    f=0;
        int l=(i+j)/2;
    if(l-1>i&&a[l-1]-a[i]<=m&&a[j]-a[l-1]<=m)f++;

    if(a[l]-a[i]<=m&&a[j]-a[l]<=m)f++;

    if(a[j]-a[l+1]<=m&&a[l+1]-a[i]<=m)f++;

    if(l-2>i&&a[l-2]-a[i]<=m&&a[j]-a[l-2]<=m)f++;

    if(l+2<j&&a[l+2]-a[i]<=m&&a[j]-a[l+2]<=m)f++;
    if(f==2) {
    s++;
    }
    }
    }
        cout<<s<<" ";
        }
        return 0;}
        for(int c=1;c<=k;c++){
                s=0;
            cin>>n>>m;
            fill(a,a+1+n,0);
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                    b[i][j]=1e5+7;
                    d[i][j]=1;
        }
                }
            for(int i=1;i<=n;i++){
                cin>>a[i];
                b[i][i]=0;
                b[i][i+1]=1;
                }
        ff(1,n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]==2)s++;
                }
        }
        cout<<s<<" ";
        }
}
