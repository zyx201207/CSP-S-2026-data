#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){

        int s=0,d[300005],x[500005];
        for(int j=1;j<=m;j++)d[j]=0;
        for(int j=1;j<=n;j++)x[i]=0;
        for(int j=i;j<=n;j++){

           x[++s]=a[j];
           if(d[a[j]]==0)d[a[j]]=s;
            else{

               for(int g=1+d[a[j]];g<s;g++){
                    d[x[g]]=0;
                    x[g]=0;
              }
                s=d[a[j]];
            }
        //    for(int i=1;i<=m;i++)cout<<d[i]<<' ';
          //  cout<<endl;
        }
        //cout<<endl;
        for(int j=1;j<=s;j++){
            ans[x[j]]++;
        }

    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
