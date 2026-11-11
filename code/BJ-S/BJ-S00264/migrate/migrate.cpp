#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005,partN=305,inf=2e18;
int read(){int x=0,b=1;char c;for(;!isdigit(c);c=getchar()){if(c=='-'){b=-1;}}for(;isdigit(c);c=getchar()){x=x*10+c-'0';}return x*b;}
int id,t,n,d,x[N],f[N],pre[N],last[N],dis[partN][partN];
int solve(){
    n=read();
    d=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
    }
    if(id<=6){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    dis[i][j]=0;
                }
                else if(abs(x[i]-x[j])<=d){
                    dis[i][j]=1;
                }
                else{
                    dis[i][j]=inf;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                int sum=0;
                for(int k=j+1;k<=i-1;k++){
                    if(dis[i][j]==dis[i][k]+dis[k][j]){
                        sum++;
                    }
                }
                ans+=sum==2;
            }
        }
        return ans;
    }
    int l=1;
    for(int r=1;r<=n;r++){
        while(l<r&&x[r]-x[l]>d){
            l++;
        }
        last[r]=l;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int len=i-last[i];
        if(len==0){
            //gummu
        }
        if(len==1){
            for(int j=last[i];j<i;j++){
                ans+=f[j];
            }
        }
        if(len>=2){
            int l=last[last[i]+2];
            int r=last[last[i]+3]-1;
            f[i]=r-l+1;
            ans+=f[i];
        }
    }
    return ans;
    /*
    xia jb xie de O(n^2) gan jue bu dui
    wo tao yan O(n) dp
    */
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    id=read();
    t=read();
    while(t--){
        cout<<solve()<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
