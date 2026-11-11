#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[500005],ans[300005],k[500005],aa[500005],y[500005],yy[500005],A=true,cnt,cn;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) A=false;
        if(a[i]!=a[i-1]) cnt++;
        aa[i]=a[i];
    }
    if(n<=5000){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) a[j]=aa[j];
            for(int j=i;j<=n;j++){
                if(t[a[j]]==0) t[a[j]]+=j;
                else{
                    for(int u=t[a[j]];u<j;u++){
                        t[a[u]]-=u;
                        a[u]=0;
                    }
                    t[a[j]]+=j;
                }
            }
            for(int i=1;i<=m;i++){
                if(t[i]!=0) ans[i]++;
                t[i]=0;
            }
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }else if(A){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                ans[a[i]]+=i;
            }else{
                ans[a[i]]++;
            }
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }else{
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                y[++cn]=a[i];
                yy[cn]=a[i];
                k[cn-1]=sum;
                sum=0;
            }
            sum++;
        }
        //for(int i=1;i<=cn;i++) cout<<y[i]<<" ";
        //cout<<"\n";
        for(int i=1;i<=cn;i++){
            for(int j=1;j<=cn;j++) y[j]=yy[j];
            for(int j=i;j<=cn;j++){
                if(t[y[j]]==0) t[y[j]]+=j;
                else{
                    for(int u=t[y[j]];u<j;u++){
                        t[y[u]]-=u;
                        y[u]=0;
                    }
                    t[y[j]]+=j;
                }
            }
            for(int j=1;j<=m;j++){
                if(t[j]!=0) ans[j]+=k[i];
                t[j]=0;
            }
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }
    return 0;
}

