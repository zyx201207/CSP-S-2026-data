#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],maxa=-1e10,mina=1e9,m,maxans=1;int n,ok=1;
//bool b[500005];


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //if(a[i]==i)b[i]=1;
        maxa=maxa>a[i]?maxa:a[i];
        mina=mina<a[i]?mina:a[i];

    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        //if(b[i]!=1)ok=0;

    }

        for(int i=0;i<=maxa-mina;i++){
            long long shu=mina+i;int k;
            for(int j=1;j<=n;j++)if(a[j]>shu){k=j-1;break;}
            if(i==maxa-mina)k=n;
            //cout<<k<<" ";
            for(int j=0;j<=k-1;j++){

                if(k-j-1>-1)if(shu*(j+1)-sum[k]<=m-sum[k-j-1]){maxans=maxans>j+1?maxans:j+1;}
            }
        }
        cout<<maxans;

return 0;
}