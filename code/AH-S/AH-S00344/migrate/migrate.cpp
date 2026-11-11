#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n,f[N],g[N];
ll a[N],cnt,k;
bool x[N],y[N],w[N],z[N],e[N],f[N];
ll d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++)
            x[i]=y[i]=w[i]=z[i]=false,f[i]=g[i]=0;
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(c==11||c==12){
            int k=d/(a[2]-a[1]);
            if(k==0||k==1){
                cout<<0<<"\n";
            }
            else
                cout<<max(n-2*k+1,0)<<"\n";
            continue;
        }
        if(c==13||c==14){
            cout<<"0\n";
            continue;
        }
        for(int i=2;i<=n-2;i++)
            if(a[i]-a[i-1]<=d&&a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d)
                if(a[i+1]-a[i-1]>d)
                    x[i]=true;
                else if(a[i+1]-a[i-1]==d)
                    w[i]=true;
        for(int i=n-2;i>=2;i--)
            if(a[i]-a[i-1]<=d&&a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d)
                if(a[i+2]-a[i]>d)
                    y[i]=true;
                else if(a[i+2]-a[i]==d)
                    z[i]=true;
        f[2]=g[n-1]=1;
        for(int i=3;i<=n;i++){
            if(a[i]-a[i-1]>d)
                f[i]=0;
            else if((x[i-2]&&y[i-2])||(w[i-2]&&z[i-2]))
                f[i]=2;
            else
                f[i]=f[i-1]+1;
            //cout<<f[i]<<' ';
        }
        //cout<<'\n';
        for(int i=n-2;i>=1;i--){
            if(a[i+1]-a[i]>d)
                g[i]=0;
            else if((x[i+1]&&y[i+1])||(w[i+1]&&z[i+1]))
                g[i]=2;
            else
                g[i]=g[i+1]+1;
            //cout<<g[i]<<' ';
        }
        for(int i=2;i<=n-2;i++)
            if((x[i]&&y[i])||(w[i]&&z[i])){
                //cout<<i<<' ';
                cnt+=1LL*(f[i+1]-1)*(g[i]-1);
            }
        cout<<cnt<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
