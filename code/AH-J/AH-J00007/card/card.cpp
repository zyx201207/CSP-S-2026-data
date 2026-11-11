#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],b[100010],f=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i-1]>a[i])f=0;
    }
    if(f){
        ll o=1;
        for(int i=1;i<=n;i++){
            if(o!=a[i]){
                b[a[i]-1]=i-1;
            }
            o=a[i];
        }
        b[a[n]]=n;
        for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    }
    else{
        for(int i=1;i<=n;i++){
            bool v[3010]={};
            bool v1[200010]={};
            for(int j=i;j<=n;j++){
                if(v[a[j]]){
                    for(int k=j-1;k>=i;k--){
                        if(a[k]==a[j]&&!v1[k]){
                            v1[k]=1;
                            break;
                        }
                        v1[k]=1;
                    }
                }
                else{
                    v[a[j]]++;
                }
            }
            for(int j=i;j<=n;j++){
                if(!v1[j])b[a[j]]++;
            }
        }
        for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    }
    return 0;
}
