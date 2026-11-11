#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5E5+10,M=3E5;
int a[M],b[M],n,m,x[N],c[N+M],sum;
bool ok,ok1;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(;;){
    for(int i=1;i<=n;i++)cin>>x[i],a[x[i]]++;
    for(int i=1;i<=n;i++){
        sum++;
        for(int j=1;j<=sum;j++){
            if(c[j]==x[i]){
                memset(c,0,sizeof(c));
                ok=false;
                break;
            }
        }if(ok)c[sum]=x[i];
        else c[1]=x[i],sum=0;
    }for(int i=1;i<=sum;i++){
        b[c[i]]++;
        a[c[i]]--;
        if(a[i]!=0)ok1=true;
    }if(!ok)break;
    }for(int i=1;i<=m;i++){
        cout<<b[i];
    }
}

