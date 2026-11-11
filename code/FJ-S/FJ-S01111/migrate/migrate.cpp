#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+3;
int oc,T,n,a[N],b[N];
ll d,x[N],g[N],f[N],s[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>oc>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(n<=3){cout<<"0\n";continue;}
        for(int i=1,j=1;i<=n;i++){
            while(j<n&&x[j+1]-x[i]<=d)++j;
            a[i]=j;
        }
        for(int i=n,j=n;i>=1;i--){
            while(j>1&&x[i]-x[j-1]<=d)--j;
            b[i]=j;
        }
        for(int i=1;i<=n;i++){
            g[i]=1;f[i]=0;
            if(b[i]==i)continue;
            if(a[b[i]]==i)g[i]+=g[b[i]];
            if(a[b[i]]==i&&(a[b[b[i]]]==b[i]||a[b[b[i]]+1]==b[i]))f[i]+=f[b[i]];
            if(b[i]==i-1)continue;
            for(int j=1;j<b[i];j++)if(a[j]==b[i]+1){
                //cout<<i<<' '<<j<<'\n';
                if(b[j]>=j-1)f[i]+=g[j];
                else ++f[i];
            }
        }
        s[n]=0;
        for(int i=1;i<=n;i++){
            //cout<<i<<' '<<f[i]<<' '<<g[i]<<'\n';
            s[n]+=f[i];
        }
        cout<<s[n]<<'\n';
    }
    return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/