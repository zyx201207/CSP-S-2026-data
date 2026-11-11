#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005],c[1000005],d[1000005];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int o=0;o<n;o++){
        a[o]=0;
        c[1000005]={ };
        for(int i=o+1;i<=n;i++){
            if(b[a[i]]==0){
                b[a[i]]=1;
                c[a[i]]=1ll*i;
            }else{
                for(int j=c[a[i]];j<i;j++){
                    b[a[j]]=0;
                }
                b[a[i]]=1;
                c[a[i]]=i;
            }
        }
        for(int i=1;i<n;i++){
            if(b[a[i]]==1) d[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}

