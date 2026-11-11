#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[5000],b[5000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[a[j]]++;
            if(b[a[j]]>=2){
                for(int y=0;y<a[j];y++){
                    b[y]=1;
                }
            }
            b[a[j]]=1;
        }
        for(int y=1;y<=n;y++){
            ans[y]+=b[y];
            b[y]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    }
