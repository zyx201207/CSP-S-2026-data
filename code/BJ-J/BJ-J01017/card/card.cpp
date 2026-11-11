#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005],z[200005],c,d;
int main(){
    freopen("card.in",'r',stdin);
    freopen("card.out",'w',stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=500&&m<=200){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                bool f=1;
                d++;
                for(int k=j;k<=n;k++){
                    if(a[j]==z[k])f=0;
                    if(!f){
                        z[i]=0;
                        d--;
                        continue;
                    }
                }
                z[d]=a[j];
            }
            for(int j=1;j<=n;j++){
                sum[z[j]]++;
            }
        }
        for(int i=1;i<=m;i++)cout<<sum[i]<<' ';
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                cout<<i<<' ';
                c=0;
            }
            else{
                c++;
                cout<<c+i<<' ';
            }
        }
    }
    return 0;
}
