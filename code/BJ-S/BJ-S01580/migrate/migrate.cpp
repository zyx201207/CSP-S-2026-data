#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,ans;
int n,d;
int x[2000010],a[20010][20010],b[2000010];
int st[2000010];
void dfs(int x1,int y,int step,int l,int r){
    if(x1<l||x1>r){
        return;
    }
    if(x1==y) {
        st[step]++;
        //cout<<step<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[x1][i]&&!b[i]){
            //cout<<x1<<" "<<i<<endl;
            for(int j=x1+1;j<=i;j++){
                b[j]=1;
            }
            dfs(i,y,step+1,l,r);
            for(int j=x1+1;j<=i;j++){
                b[j]=0;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=min(n,20000);i++){
            for(int j=1;j<=min(n,20000);j++){
                if(i!=j){
                    if(abs(x[i]-x[j])<=d){
                        a[i][j]=a[j][i]=1;
                    }
                }

            }
        }
/*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int k=1;k<=n;k++){
            b[k]=0;
            //cout<<b[k]<<" ";
        }
        //cout<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //cout<<i<<"&"<<j<<endl;
                b[i]=1;

                dfs(i,j,0,min(i,j),max(i,j));
                memset(b,0,n);
                int rr=0;
                for(int k=1;k<=n;k++){
                    //cout<<st[k]<<" ";
                    if(st[k]!=2&&st[k]>0) rr=1;
                    if(st[k]==2&&rr==0){
                        //cout<<i<<" "<<j<<endl;
                        ans++;
                    }
                }
                memset(st,0,sizeof(st));
                //cout<<endl;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=0;
            }
        }
        n=0,d=0;
        memset(x,0,n);
    }
    return 0;
}
